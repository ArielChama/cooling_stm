

void VDCU_CAN_SendTemp(int16_t temp[])
{
  FDCAN_TxHeaderTypeDef tx_header;
  BytesUnion tx_data;

  tx_header.Identifier = 0x129;
  tx_header.IdType = FDCAN_STANDARD_ID;
  tx_header.TxFrameType = FDCAN_DATA_FRAME;
  tx_header.DataLength = FDCAN_DLC_BYTES_8;
  tx_header.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
  tx_header.BitRateSwitch = FDCAN_BRS_OFF;
  tx_header.FDFormat = FDCAN_CLASSIC_CAN;
  tx_header.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
  tx_header.MessageMarker = 0;

  tx_data.s0 = temp[0];
  tx_data.s1 = temp[1];
  tx_data.s2 = temp[2];

  HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &tx_header, tx_data.byte);
}
