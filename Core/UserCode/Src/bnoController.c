#include "bno055.h"
#include "bnoController.h"
#include "vdcu_can.h"

// Variáveis para armazenar o estado (devem ser persistentes)
bno055_vec3_t velocity = {0.0f, 0.0f, 0.0f};
bno055_vec3_t position = {0.0f, 0.0f, 0.0f};
uint32_t lastTick = 0;



void BnoController() {
	bno055_t bno = (bno055_t){
        .i2c = &hi2c3, .addr = BNO_ADDR, .mode = BNO_MODE_IMU,
    };

    bno055_init(&bno);
    lastTick = HAL_GetTick();

    bno055_vec3_t linear_acc;

    while (true) {
        // 1. Calcular o tempo decorrido (dt) em segundos
        uint32_t currentTick = HAL_GetTick();
        float dt = (float)(currentTick - lastTick) / 1000.0f;
        lastTick = currentTick;

        // Evitar dt zero ou valores estranhos no primeiro ciclo
        if (dt <= 0.0f) continue;

        // 2. Ler a Aceleração Linear (sem gravidade)
        bno.linear_acc(&bno, &linear_acc);

        // 3. Filtro de Ruído (Deadband)
        // O sensor tem ruído. Se não filtrares pequenos valores, a posição vai "derivar"
        if (linear_acc.x > -0.1f && linear_acc.x < 0.1f) linear_acc.x = 0;
        if (linear_acc.y > -0.1f && linear_acc.y < 0.1f) linear_acc.y = 0;
        if (linear_acc.z > -0.1f && linear_acc.z < 0.1f) linear_acc.z = 0;

        // 4. Integração para Velocidade (v = v0 + a*dt)
        velocity.x += linear_acc.x * dt;
        velocity.y += linear_acc.y * dt;
        velocity.z += linear_acc.z * dt;

        // 5. Integração para Posição (s = s0 + v*dt)
        position.x += velocity.x * dt;
        position.y += velocity.y * dt;
        position.z += velocity.z * dt;

        // Pequeno delay para não sobrecarregar o processador
        HAL_Delay(10);


        // Enviar pela CAN apenas a cada 100ms (10Hz)
        static uint32_t lastCanTick = 0;
		if (HAL_GetTick() - lastCanTick >= 100) {
			VDCU_CAN_SendPosition(position.x, position.y, position.z);
			lastCanTick = HAL_GetTick();
		}
    }

}
