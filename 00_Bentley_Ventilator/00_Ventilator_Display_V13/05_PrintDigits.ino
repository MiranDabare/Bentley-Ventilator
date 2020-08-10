void printDigits(int digits)  // utility function for digital clock display: prints preceding colon and leading 0
{
  tft.print(":");
  if(digits < 10)
  tft.print('0');
  tft.print(digits);
}
