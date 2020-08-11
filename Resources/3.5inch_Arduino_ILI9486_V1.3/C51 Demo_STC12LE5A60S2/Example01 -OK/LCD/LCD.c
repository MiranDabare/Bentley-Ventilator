#include "sys.h"
#include "lcd.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//����Ӳ������Ƭ��STC12LE5A60S2,����30M  ��Ƭ��������ѹ3.3V
//QDtech-TFTҺ������ for C51
//xiao��@ShenZhen QDtech co.,LTD
//��˾��վ:www.qdtech.net
//�Ա���վ��http://qdtech.taobao.com
//��˾�ṩ����֧�֣��κμ������⻶ӭ��ʱ����ѧϰ
//�̻�(����) :+86 0755-23594567 
//�ֻ�:15989313508���빤�� 
//����:QDtech2008@gmail.com 
//Skype:QDtech2008
//��������QQȺ:324828016
//��������:2013/5/13
//�汾��V1.1
//��Ȩ���У�����ؾ���
//Copyright(C) ������ȫ�����Ӽ������޹�˾ 2009-2019
//All rights reserved
//********************************************************************************

/****************************************************************************************************
//=========================================��Դ����================================================//
//5V��DC 5V��Դ
//3V3 ���ý�
//GND�ӵ�
//=======================================Һ���������߽���==========================================//
//��ģ��Ĭ��������������Ϊ8λ����ģʽ
//8λģʽ���ߣ�
//Һ����LCD_D0��Ӧ��Ƭ��P0.0
//Һ����LCD_D1��Ӧ��Ƭ��P0.1
//Һ����LCD_D2��Ӧ��Ƭ��P0.2
//Һ����LCD_D3��Ӧ��Ƭ��P0.3
//Һ����LCD_D4��Ӧ��Ƭ��P0.4
//Һ����LCD_D5��Ӧ��Ƭ��P0.5
//Һ����LCD_D6��Ӧ��Ƭ��P0.6
//Һ����LCD_D7��Ӧ��Ƭ��P0.7
//=======================================Һ���������߽���==========================================//
//LCD_RST	��P3.3	//��λ�ź�
//LCD_CS	��P1.3	//Ƭѡ�ź�
//LCD_RS	��P1.2	//�Ĵ���/����ѡ���ź�
//LCD_WR	��P1.1	//д�ź�
//LCD_RD	��P1.0	//���ź�
//=========================================������������=========================================//
//�����򲻽��д������ԡ�
//������Դ������ܣ���ʹ��Arduino���׳�����в���
**************************************************************************************************/	



//LCD�Ļ�����ɫ�ͱ���ɫ	   
u16 POINT_COLOR=0x0000;	//������ɫ
u16 BACK_COLOR=0xFFFF;  //����ɫ 
//����LCD��Ҫ����
//Ĭ��Ϊ����
_lcd_dev lcddev;



//******************************************************************
//��������  LCD_Write_Bus
//���ߣ�    xiao��@ȫ������
//���ڣ�    2013-02-22
//���ܣ�    ��Һ��������д������(LCD�����ڲ�����)
//���������VH:��8λ����
//        	VL:��8λ����
//����ֵ��  ��
//�޸ļ�¼����
//******************************************************************

void LCD_Write_Bus(char VH,char VL)   
{
	LCD_CS=0;	
	LCD_DataPortH=VH;	
	LCD_DataPortL=VL;		
	LCD_WR=0;
	LCD_WR=1; 
	LCD_CS=1;
}



//******************************************************************
//��������  LCD_WR_DATA8
//���ߣ�    xiao��@ȫ������
//���ڣ�    2013-02-22
//���ܣ�    ��Һ��������д��д8λ����
//���������VH:��8λ����
//        	VL:��8λ����
//����ֵ��  ��
//�޸ļ�¼����
//******************************************************************
void LCD_WR_DATA8(char VH,char VL) 
{
	LCD_RS=1;
	LCD_Write_Bus(VH,VL);
} 

//******************************************************************
//��������  LCD_WR_REG
//���ߣ�    xiao��@ȫ������
//���ڣ�    2013-02-22
//���ܣ�    ��Һ��������д��д16λָ��
//���������Reg:��д���ָ��ֵ
//����ֵ��  ��
//�޸ļ�¼����
//******************************************************************
void LCD_WR_REG(int Reg)	 
{	
	LCD_RS=0;
	LCD_Write_Bus(Reg>>8,Reg);
} 

//******************************************************************
//��������  LCD_WR_DATA
//���ߣ�    xiao��@ȫ������
//���ڣ�    2013-02-22
//���ܣ�    ��Һ��������д��д16λ����
//���������Data:��д�������
//����ֵ��  ��
//�޸ļ�¼����
//******************************************************************
 void LCD_WR_DATA(int Data)
{
	LCD_RS=1;
	LCD_Write_Bus(Data>>8,Data);
}

//******************************************************************
//��������  LCD_WriteReg
//���ߣ�    xiao��@ȫ������
//���ڣ�    2013-02-22
//���ܣ�    д�Ĵ�������
//���������LCD_Reg:�Ĵ�����ַ
//			LCD_RegValue:Ҫд�������
//����ֵ��  ��
//�޸ļ�¼����
//******************************************************************
void LCD_WriteReg(u16 LCD_Reg, u16 LCD_RegValue)
{
  LCD_WR_REG(LCD_Reg);
	LCD_WR_DATA(LCD_RegValue);
}

//******************************************************************
//��������  LCD_WriteRAM_Prepare
//���ߣ�    xiao��@ȫ������
//���ڣ�    2013-02-22
//���ܣ�    ��ʼдGRAM
//			�ڸ�Һ��������RGB����ǰ��Ӧ�÷���дGRAMָ��
//�����������
//����ֵ��  ��
//�޸ļ�¼����
//******************************************************************
void LCD_WriteRAM_Prepare(void)
{
 	LCD_WR_REG(lcddev.wramcmd);	  
}


//******************************************************************
//��������  LCD_Clear
//���ߣ�    xiao��@ȫ������
//���ڣ�    2013-02-22
//���ܣ�    LCDȫ�������������
//���������Color:Ҫ���������ɫ
//����ֵ��  ��
//�޸ļ�¼����
//******************************************************************
void LCD_Clear(u16 Color)
{
	u32 index=0;      
	LCD_SetWindows(0,0,lcddev.width-1,lcddev.height-1);	
#if LCD_USE8BIT_MODEL==1
	LCD_RS=1;//д���� 
	LCD_CS=0;	   
	for(index=0;index<lcddev.width*lcddev.height;index++)
	{
		LCD_DataPortL=(Color>>8);	
		LCD_WR=0;
		LCD_WR=1;	
		
		LCD_DataPortL=Color;	
		LCD_WR=0;
		LCD_WR=1;   
	}
	LCD_CS=1;	
#else //16λģʽ
	for(index=0;index<lcddev.width*lcddev.height;index++)
	{
		LCD_WR_DATA(Color);		  
	}
#endif
	
} 

//******************************************************************
//��������  LCD_DrawPoint
//���ߣ�    xiao��@ȫ������
//���ڣ�    2013-02-22
//���ܣ�    ��ָ��λ��д��һ�����ص�����
//���������(x,y):�������
//����ֵ��  ��
//�޸ļ�¼����
//******************************************************************
void LCD_DrawPoint(u16 x,u16 y)
{
	LCD_SetCursor(x,y);//���ù��λ�� 
#if LCD_USE8BIT_MODEL==1
	LCD_CS=0;
	LCD_RD=1;
	LCD_RS=1;//д��ַ  	 
	LCD_DataPortL=(POINT_COLOR>>8);	
	LCD_WR=0;
	LCD_WR=1;
	LCD_DataPortL=POINT_COLOR;	
	LCD_WR=0;
	LCD_WR=1;	 
	LCD_CS=1;
#else
	LCD_WR_DATA(POINT_COLOR); 
#endif
}	 
//******************************************************************
//��������  LCD_DrawPoint_16Bit
//���ߣ�    xiao��@ȫ������
//���ڣ�    2013-02-22
//���ܣ�    8λ���������д��һ��16λ����
//���������(x,y):�������
//����ֵ��  ��
//�޸ļ�¼����
//******************************************************************
void LCD_DrawPoint_16Bit(u16 color)
{
#if LCD_USE8BIT_MODEL==1
	LCD_CS=0;
	LCD_RD=1;
	LCD_RS=1;//д��ַ  	 
	LCD_DataPortL=(color>>8);	
	LCD_WR=0;
	LCD_WR=1;
	LCD_DataPortL=color;	
	LCD_WR=0;
	LCD_WR=1;	 
	LCD_CS=1;
#else
	LCD_WR_DATA(color); 
#endif


}
//******************************************************************
//��������  LCD_Reset
//���ߣ�    xiao��@ȫ������
//���ڣ�    2013-02-22
//���ܣ�    LCD��λ������Һ����ʼ��ǰҪ���ô˺���
//�����������
//����ֵ��  ��
//�޸ļ�¼����
//******************************************************************
void LCD_Reset(void)
{
	LCD_RESET=1;
	delay_ms(50);	
	LCD_RESET=0;
	delay_ms(50);
	LCD_RESET=1;
	delay_ms(50);
}

//******************************************************************
//��������  LCD_Init
//���ߣ�    xiao��@ȫ������
//���ڣ�    2013-02-22
//���ܣ�    LCD��ʼ��
//�����������
//����ֵ��  ��
//�޸ļ�¼����
//******************************************************************
void LCD_Init(void)
{
	LCD_Reset(); //��ʼ��֮ǰ��λ
	LCD_RD=1;	 //RD����û���õ������ߴ���

	//ILI9486��ʼ��
	LCD_WR_REG(0XF9);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x08);
	
	LCD_WR_REG(0xC0);
	LCD_WR_DATA(0x19);//VREG1OUT POSITIVE
	LCD_WR_DATA(0x1a);//VREG2OUT NEGATIVE
	
	LCD_WR_REG(0xC1);
	LCD_WR_DATA(0x45);//VGH,VGL    VGH>=14V.
	LCD_WR_DATA(0x00);
	
	LCD_WR_REG(0xC2);
	LCD_WR_DATA(0x33);
	
	LCD_WR_REG(0XC5);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x28);//VCM_REG[7:0]. <=0X80.
		
	LCD_WR_REG(0xB1);//OSC Freq set.
	LCD_WR_DATA(0x90);//0xA0=62HZ,0XB0 =70HZ, <=0XB0.
	LCD_WR_DATA(0x11);
	
	LCD_WR_REG(0xB4);
	LCD_WR_DATA(0x02); //2 DOT FRAME MODE,F<=70HZ.
	
	LCD_WR_REG(0xB6);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x42);//0 GS SS SM ISC[3:0];
	LCD_WR_DATA(0x3B);
		
	LCD_WR_REG(0xB7);
	LCD_WR_DATA(0x07);
	
	LCD_WR_REG(0xE0);
	LCD_WR_DATA(0x1F);
	LCD_WR_DATA(0x25);
	LCD_WR_DATA(0x22);
	LCD_WR_DATA(0x0B);
	LCD_WR_DATA(0x06);
	LCD_WR_DATA(0x0A);
	LCD_WR_DATA(0x4E);
	LCD_WR_DATA(0xC6);
	LCD_WR_DATA(0x39);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x00);
	
	LCD_WR_REG(0XE1);
	LCD_WR_DATA(0x1F);
	LCD_WR_DATA(0x3F);
	LCD_WR_DATA(0x3F);
	LCD_WR_DATA(0x0F);
	LCD_WR_DATA(0x1F);
	LCD_WR_DATA(0x0F);
	LCD_WR_DATA(0x46);
	LCD_WR_DATA(0x49);
	LCD_WR_DATA(0x31);
	LCD_WR_DATA(0x05);
	LCD_WR_DATA(0x09);
	LCD_WR_DATA(0x03);
	LCD_WR_DATA(0x1C);
	LCD_WR_DATA(0x1A);
	LCD_WR_DATA(0x00);
	
	LCD_WR_REG(0XF1);
	LCD_WR_DATA(0x36);
	LCD_WR_DATA(0x04);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x3C);
	LCD_WR_DATA(0x0F);
	LCD_WR_DATA(0x0F);
	LCD_WR_DATA(0xA4);
	LCD_WR_DATA(0x02);
	
	LCD_WR_REG(0XF2);
	LCD_WR_DATA(0x18);
	LCD_WR_DATA(0xA3);
	LCD_WR_DATA(0x12);
	LCD_WR_DATA(0x02);
	LCD_WR_DATA(0x32);
	LCD_WR_DATA(0x12);
	LCD_WR_DATA(0xFF);
	LCD_WR_DATA(0x32);
	LCD_WR_DATA(0x00);
	
	LCD_WR_REG(0XF4);
	LCD_WR_DATA(0x40);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x08);
	LCD_WR_DATA(0x91);
	LCD_WR_DATA(0x04);
	
	LCD_WR_REG(0XF8);
	LCD_WR_DATA(0x21);
	LCD_WR_DATA(0x04);
	
	LCD_WR_REG(0x36);
	LCD_WR_DATA(0x48);
	
	LCD_WR_REG(0x3A);
	LCD_WR_DATA(0x55);
	
	LCD_WR_REG(0x11);
	delay_ms(120);
	//LCD_WR_REG(0x21);
	LCD_WR_REG(0x29);

	//����LCD���Բ���
	LCD_SetParam();//����LCD����	 
	LCD_BL=1;//��������	 
}
//******************************************************************
//��������  LCD_SetWindows
//���ߣ�    xiao��@ȫ������
//���ڣ�    2013-02-22
//���ܣ�    ������ʾ����
//���������(xStar,yStar):�������Ͻ���ʼ����
//	 	   	(xEnd,yEnd):�������½ǽ�������
//����ֵ��  ��
//�޸ļ�¼����
//******************************************************************
void LCD_SetWindows(u16 xStar, u16 yStar,u16 xEnd,u16 yEnd)
{	
	LCD_WR_REG(lcddev.setxcmd);	
	LCD_WR_DATA(xStar>>8);
	LCD_WR_DATA(0x00FF&xStar);		
	LCD_WR_DATA(xEnd>>8);
	LCD_WR_DATA(0x00FF&xEnd);

	LCD_WR_REG(lcddev.setycmd);	
	LCD_WR_DATA(yStar>>8);
	LCD_WR_DATA(0x00FF&yStar);		
	LCD_WR_DATA(yEnd>>8);
	LCD_WR_DATA(0x00FF&yEnd);

	LCD_WriteRAM_Prepare();	//��ʼд��GRAM			
}   

//******************************************************************
//��������  LCD_SetCursor
//���ߣ�    xiao��@ȫ������
//���ڣ�    2013-02-22
//���ܣ�    ���ù��λ��
//���������Xpos:������
//			Ypos:������
//����ֵ��  ��
//�޸ļ�¼����
//******************************************************************
void LCD_SetCursor(u16 Xpos, u16 Ypos)
{	  	    			
	LCD_WR_REG(lcddev.setxcmd);	
	LCD_WR_DATA(Xpos>>8);
	LCD_WR_DATA(0x00FF&Xpos);		
	LCD_WR_DATA((Xpos+1)>>8);
	LCD_WR_DATA((Xpos+1));
	
	LCD_WR_REG(lcddev.setycmd);	
	LCD_WR_DATA(Ypos>>8);
	LCD_WR_DATA(0x00FF&Ypos);		
	LCD_WR_DATA((Ypos+1)>>8);
	LCD_WR_DATA((Ypos+1));
	LCD_WriteRAM_Prepare();	//��ʼд��GRAM		
} 

//******************************************************************
//��������  LCD_SetParam
//���ߣ�    xiao��@ȫ������
//���ڣ�    2013-02-22
//���ܣ�    ����LCD������������к�����ģʽ�л�
//�����������
//����ֵ��  ��
//�޸ļ�¼����
//******************************************************************
void LCD_SetParam(void)
{ 
	lcddev.setxcmd=0x2A;
	lcddev.setycmd=0x2B;
	lcddev.wramcmd=0x2C;
#if USE_HORIZONTAL==1	//ʹ�ú���	  
	lcddev.dir=1;//����
	lcddev.width=480;
	lcddev.height=320;			
	LCD_WriteReg(0x36,(1<<3)|(1<<7)|(1<<5));//BGR==1,MY==1,MX==0,MV==1
#else//����
	lcddev.dir=0;//����				 	 		
	lcddev.width=320;
	lcddev.height=480;	
	LCD_WriteReg(0x36,(1<<3)|(1<<6)|(1<<7));//BGR==1,MY==0,MX==0,MV==0
#endif
}	  

void LCD_direction(u8 direction )
{ 
	switch(direction){
		case 3:
			lcddev.width=480;
			lcddev.height=320;
			LCD_WriteReg(0x36,(1<<3)|(1<<7)|(1<<5));//BGR==1,MY==1,MX==0,MV==1
		break;
		case 1:
			lcddev.width=480;
			lcddev.height=320;
			LCD_WriteReg(0x36,(1<<3)|(0<<7)|(1<<6)|(1<<5));//BGR==1,MY==1,MX==0,MV==1
		break;
		case 2:						 	 		
			lcddev.width=320;
			lcddev.height=480;	
			LCD_WriteReg(0x36,(1<<3)|(1<<6)|(1<<7));//BGR==1,MY==0,MX==0,MV==0
		break;
		case 0:						 	 		
			lcddev.width=320;
			lcddev.height=480;	
			LCD_WriteReg(0x36,(1<<3)|(0<<6)|(0<<7));//BGR==1,MY==0,MX==0,MV==0
		break;
		default:break;
	}
		

}	 





