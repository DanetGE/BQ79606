#include <Arduino.h>
//#include <BQ79606.h>
#include "BQ79606.h"



void setup() {

  Ini_ESP();

  Wake79606();

  CommReset();

  AutoAddress();


  InitDevices();

  WriteReg(0, SYSFLT1_FLT_RST, 0xFFFFFF, 3, FRMWRT_ALL_NR);   //reset system faults
  WriteReg(0, SYSFLT1_FLT_MSK, 0xFFFFFF, 3, FRMWRT_ALL_NR);
  WriteReg(0, CONTROL2, 0x10, 1, FRMWRT_ALL_NR);          //tsref activo
  
  //SET UP MAIN ADC
  WriteReg(0, CELL_ADC_CTRL, 0x3F, 1, FRMWRT_ALL_NR);     //enable conversions for all cells
  WriteReg(0, CELL_ADC_CONF2, 0x08, 1, FRMWRT_ALL_NR);    //set continuous ADC conversions, and set minimum conversion interval

  WriteReg(0, GPIO1_CONF, 0x20, 1, FRMWRT_ALL_NR);       //GPIO is an input
  WriteReg(0, GPIO2_CONF, 0x20, 1, FRMWRT_ALL_NR);       //GPIO is an input
  WriteReg(0, GPIO3_CONF, 0x20, 1, FRMWRT_ALL_NR);       //GPIO is an input
  WriteReg(0, GPIO4_CONF, 0x20, 1, FRMWRT_ALL_NR);       //GPIO is an input
  WriteReg(0, GPIO5_CONF, 0x20, 1, FRMWRT_ALL_NR);       //GPIO is an input
  WriteReg(0, GPIO6_CONF, 0x20, 1, FRMWRT_ALL_NR);       //GPIO is an input

  WriteReg(0, AUX_ADC_CTRL1, 0xF0, 1, FRMWRT_ALL_NR);       //GPIO is an input
  WriteReg(0, AUX_ADC_CTRL2, 0x03, 1, FRMWRT_ALL_NR);       //GPIO is an input


  WriteReg(0, CONTROL2, 0x13, 1, FRMWRT_ALL_NR);          //CELL_ADC_GO = 1 Y tsref y AUX_ADC_GO = 1


  delay(3*TOTALBOARDS+901);                             //3us of re-clocking delay per board + 901us waiting for first ADC conversion to complete
  
  
//Serial2.println("OK");*/
}

void loop() {
    delay(10);
    //VARIABLES
    byte response_frame[(MAXBYTES+6)];
    byte response_frame2[(MAXBYTES+6)];
    int currentBoard = 0;
    int Bytesleidos = 0;
    int i = 0;

    //reset variables
        memset(response_frame, 0, sizeof(response_frame));
        i = 0;
        currentBoard=0;

        

        WriteReg(0, CONTROL2, 0x13, 1, FRMWRT_ALL_NR);

        delay(20);

        

        /*
         * ***********************************************
         * NOTE: SOME COMPUTERS HAVE ISSUES TRANSMITTING
         * A LARGE AMOUNT OF DATA VIA PRINTF STATEMENTS.
         * THE FOLLOWING PRINTOUT OF THE RESPONSE DATA
         * IS NOT GUARANTEED TO WORK ON ALL SYSTEMS.
         * ***********************************************
        */
        
        if(Bytesleidos == -1){
          Serial.println("No se ha podido leer los datos, se ha excedido el tiempo");
          //delay(1000);
        }
        else{

        
          //PARSE, FORMAT, AND PRINT THE DATA
          for(currentBoard = 0; currentBoard<TOTALBOARDS; currentBoard++)
          {   
              memset(response_frame, 0, sizeof(response_frame));
              memset(response_frame2, 0, sizeof(response_frame));
              //read back data (6 cells and 2 bytes each cell)
              Bytesleidos = ReadReg(currentBoard, VCELL1H, response_frame, MAXBYTES, 0, FRMWRT_SGL_R);
              Bytesleidos = ReadReg(currentBoard, AUX_GPIO1H, response_frame2, MAXBYTES, 0, FRMWRT_SGL_R);
              //response frame actually starts with top of stack, so currentBoard is actually inverted from what it should be
              Serial.println((String)"Num board= "+currentBoard);

              //go through each byte in the current board (12 bytes = 6 cells * 2 bytes each)
              for(i=0; i<12; i+=2)
              {
                //each board responds with 32 data bytes + 6 header bytes
                //so need to find the start of each board by doing that * currentBoard


                //convert the two individual bytes of each cell into a single 16 bit data item (by bit shifting)
                uint16_t rawData = (response_frame[i+4] << 8) | response_frame[i+5];

                //do the two's complement of the resultant 16 bit data item, and multiply by 190.73uV to get an actual voltage
                float cellVoltage = Complement(rawData,0.00019073);
                
                if(cellVoltage >= 4.2){
                  digitalWrite(BMS_OK, LOW);
                  Serial.println("Fallo de tensión");
                }
                //print the voltages - it is i/2 because cells start from 1 up to 6
                //and there are 2 bytes per cell (i value is twice the cell number),
                //and it's +1 because cell names start with "Cell1"
                Serial.println((String)"Cell " +(i/2)+" voltage= " +cellVoltage);
              }


              //go through each byte in the current board (12 bytes = 6 GPIO * 2 bytes each)
              for(i=0; i<12; i+=2)
              {
                //each board responds with 32 data bytes + 6 header bytes

                //convert the two individual bytes of each cell into a single 16 bit data item (by bit shifting)
                uint16_t rawData = (response_frame2[i+4] << 8) | response_frame2[i+5];

                //do the two's complement of the resultant 16 bit data item, and multiply by 190.73uV to get an actual voltage
                float GPIOVoltage = Complement(rawData,0.00019073);

                //print the voltages - it is i/2 because cells start from 1 up to 6
                //and there are 2 bytes per cell (i value is twice the cell number),
                //and it's +1 because cell names start with "Cell1"
                Serial.println((String)"GPIO " +(i/2)+" Voltage= " +GPIOVoltage);
              }
          }
      }

}
