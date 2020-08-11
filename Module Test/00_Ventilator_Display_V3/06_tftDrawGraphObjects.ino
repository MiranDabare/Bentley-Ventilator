void tftDrawGraphObjects()
{
  //draw the graph objects
  tft.fillRect(11, 5, x_scale+1, 120,BLACK);
  tft.fillRect(11, 121, x_scale+1, 119, BLACK);
  tft.drawFastVLine(10, 5, 320, WHITE); // y axis
  tft.drawFastHLine(10, 160, 480, WHITE); // x axis
  tft.setTextColor(YELLOW); tft.setTextSize(1); // set parameters for y axis labels
  tft.setCursor(3, 116); tft.print("0");  // "0" at center of ya axis
  tft.setCursor(3, 6); tft.print("1023"); // "+' at top of y axis
  tft.setCursor(3, 228); tft.print("-"); // "-" at bottom of y axis

}
