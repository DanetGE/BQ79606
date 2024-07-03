#ifndef BQ_H
#define BQ_H

#include <Arduino.h>


// User defines
#define TOTALBOARDS 6    //MUST SET: total boards in the stack
#define BAUDRATE  250000    //set global baudrate
#define MAXBYTES  6*2        //6 CELLS, 2 byteS EACH
#define Wake_pin  4         //Wake up pin number in ESP32
#define Fault_pin 2          //Fault pin number in ESP32
#define BMS_OK    13          //Fault pin number in ESP32
#define BMS_RX    16         //UART RX pin for BMS
#define BMS_TX    17         //UART TX pin for BMS




#define FRMWRT_SGL_R	  0x00 // single device read 
#define FRMWRT_SGL_NR	  0x10 // single device writeBG
#define FRMWRT_STK_R	  0x20 // stack read
#define FRMWRT_STK_NR	  0x30 // stack write
#define FRMWRT_ALL_R	  0x40 // general broadcast read
#define FRMWRT_ALL_NR	  0x50 // general broadcast write
#define FRMWRT_REV_ALL_NR 0xE0 //broadcast write reverse direction

// Register defines
#define DEVADD_OTP				0x0000 // Device address OTP
#define CONFIG					0x0001 // Device configuration
#define GPIO_FLT_MSK			0x0002 // GPIO fault mask
#define UV_FLT_MSK				0x0003 // UV comparator fault mask
#define OV_FLT_MSK				0x0004 // OV comparator fault mask
#define UT_FLT_MSK				0x0005 // UT comparator fault mask
#define OT_FLT_MSK				0x0006 // OT comparator fault mask
#define TONE_FLT_MSK			0x0007 // Fault bus tone fault mask
#define COMM_UART_FLT_MSK		0x0008 // UART fault mask
#define COMM_UART_RC_FLT_MSK	0x0009 // UART receive command fault mask
#define COMM_UART_RR_FLT_MSK	0x000A // UART receive response fault mask
#define COMM_UART_TR_FLT_MSK	0x000B // UART transmit fault mask
#define COMM_COMH_FLT_MSK		0x000C // COMH bus fault mask
#define COMM_COMH_RC_FLT_MSK	0x000D // COMH bus receive command fault mask
#define COMM_COMH_RR_FLT_MSK	0x000E // COMH bus receive command fault mask
#define COMM_COMH_TR_FLT_MSK	0x000F // COMH bus transmit fault mask
#define COMM_COML_FLT_MSK		0x0010 // COML bus fault mask
#define COMM_COML_RC_FLT_MSK	0x0011 // COML bus receive command fault mask
#define COMM_COML_RR_FLT_MSK	0x0012 // COML bus receive command fault mask
#define COMM_COML_TR_FLT_MSK	0x0013 // COML bus transmit fault mask
#define OTP_FLT_MSK				0x0014 // OTP page fault mask
#define RAIL_FLT_MSK			0x0015 // Power rail fault mask
#define SYSFLT1_FLT_MSK			0x0016 // System fault 1 mask
#define SYSFLT2_FLT_MSK			0x0017 // System fault 2 mask
#define SYSFLT3_FLT_MSK			0x0018 // IC system fault 3 mask
#define OVUV_BIST_FLT_MSK		0x0019 // OVUV bist fault mask
#define OTUT_BIST_FLT_MSK		0x001A // OTUT bist fault mask
#define SPARE_01				0x001B // Spare register
#define SPARE_02				0x001C // Spare register
#define SPARE_03				0x001D // Spare register
#define SPARE_04				0x001E // Spare register
#define SPARE_05				0x001F // Spare register
#define COMM_CTRL				0x0020 // Communication control
#define DAISY_CHAIN_CTRL		0x0021 // Daisy chain RX/TX anable control
#define TX_HOLD_OFF				0x0022 // Transmitter holdoff control
#define COMM_TO					0x0023 // Communication timeout control
#define CELL_ADC_CONF1			0x0024 // Cell ADC configuration 1
#define CELL_ADC_CONF2			0x0025 // Cell ADC configuration 2
#define AUX_ADC_CONF			0x0026 // Auxiliary ADC configuration
#define ADC_DELAY				0x0027 // ADC configuration
#define GPIO_ADC_CONF			0x0028 // GPIO_ADC result configuration
#define OVUV_CTRL				0x0029 // Cell hardware protection channel control
#define UV_THRESH				0x002A // Comparator undervoltage threshold
#define OV_THRESH				0x002B // Comparator overvoltage threshold
#define OTUT_CTRL				0x002C // GPIO over and under temperature comparator control
#define OTUT_THRESH				0x002D // GPIO comparator over and under temperature threshold
#define COMP_DG					0x002E // Comparator protection deglitch
#define GPIO1_CONF				0x002F // GPIO1 configuration
#define GPIO2_CONF				0x0030 // GPIO2 configuration
#define GPIO3_CONF				0x0031 // GPIO3 configuration
#define GPIO4_CONF				0x0032 // GPIO4 configuration
#define GPIO5_CONF				0x0033 // GPIO5 configuration
#define GPIO6_CONF				0x0034 // GPIO6 configuration
#define CELL1_GAIN				0x0035 // Cell 1 gain calibration
#define CELL2_GAIN				0x0036 // Cell 2 gain calibration
#define CELL3_GAIN				0x0037 // Cell 3 gain calibration
#define CELL4_GAIN				0x0038 // Cell 4 gain calibration
#define CELL5_GAIN				0x0039 // Cell 5 gain calibration
#define CELL6_GAIN				0x003A // Cell 6 gain calibration
#define CELL1_OFF				0x003B // Cell 1 offset calibration
#define CELL2_OFF				0x003C // Cell 2 offset calibration
#define CELL3_OFF				0x003D // Cell 3 offset calibration
#define CELL4_OFF				0x003E // Cell 4 offset calibration
#define CELL5_OFF				0x003F // Cell 5 offset calibration
#define CELL6_OFF				0x0040 // Cell 6 offset calibration
#define GPIO1_GAIN				0x0041 // GPIO1 gain calibration
#define GPIO2_GAIN				0x0042 // GPIO2 gain calibration
#define GPIO3_GAIN				0x0043 // GPIO3 gain calibration
#define GPIO4_GAIN				0x0044 // GPIO4 gain calibration
#define GPIO5_GAIN				0x0045 // GPIO5 gain calibration
#define GPIO6_GAIN				0x0046 // GPIO6 gain calibration
#define GPIO1_OFF				0x0047 // GPIO1 offset calibration
#define GPIO2_OFF				0x0048 // GPIO2 offset calibration
#define GPIO3_OFF				0x0049 // GPIO3 offset calibration
#define GPIO4_OFF				0x004A // GPIO4 offset calibration
#define GPIO5_OFF				0x004B // GPIO5 offset calibration
#define GPIO6_OFF				0x004C // GPIO6 offset calibration
#define GPAUXCELL_GAIN			0x004D // GP ADC gain, CH1
#define GPAUXCELL_OFF			0x004E // GP ADC offset, CH1
#define GPAUX_GAIN				0x004F // GP ADC gain, CH2-32
#define GPAUX_OFF				0x0050 // GP ADC offset, CH2-32
#define VC1COEFF1				0x0051 // Cell 1 ADC gain correction
#define VC1COEFF2				0x0052 // Cell 1 ADC gain correction
#define VC1COEFF3				0x0053 // Cell 1 ADC gain correction
#define VC1COEFF4				0x0054 // Cell 1 ADC gain correction
#define VC1COEFF5				0x0055 // Cell 1 ADC gain correction
#define VC1COEFF6				0x0056 // Cell 1 ADC gain correction
#define VC1COEFF7				0x0057 // Cell 1 ADC gain correction
#define VC1COEFF8				0x0058 // Cell 1 ADC gain correction
#define VC1COEFF9				0x0059 // Cell 1 ADC offset/gain correction
#define VC1COEFF10				0x005A // Cell 1 ADC offset correction
#define VC1COEFF11				0x005B // Cell 1 ADC offset correction
#define VC1COEFF12				0x005C // Cell 1 ADC offset correction
#define VC1COEFF13				0x005D // Cell 1 ADC offset correction
#define VC1COEFF14				0x005E // Cell 1 ADC offset correction
#define VC2COEFF1				0x005F // Cell 2 ADC gain correction
#define VC2COEFF2				0x0060 // Cell 2 ADC gain correction
#define VC2COEFF3				0x0061 // Cell 2 ADC gain correction
#define VC2COEFF4				0x0062 // Cell 2 ADC gain correction
#define VC2COEFF5				0x0063 // Cell 2 ADC gain correction
#define VC2COEFF6				0x0064 // Cell 2 ADC gain correction
#define VC2COEFF7				0x0065 // Cell 2 ADC gain correction
#define VC2COEFF8				0x0066 // Cell 2 ADC gain correction
#define VC2COEFF9				0x0067 // Cell 2 ADC offset/gain correction
#define VC2COEFF10				0x0068 // Cell 2 ADC offset correction
#define VC2COEFF11				0x0069 // Cell 2 ADC offset correction
#define VC2COEFF12				0x006A // Cell 2 ADC offset correction
#define VC2COEFF13				0x006B // Cell 2 ADC offset correction
#define VC2COEFF14				0x006C // Cell 2 ADC offset correction
#define VC3COEFF1				0x006D // Cell 3 ADC gain correction
#define VC3COEFF2				0x006E // Cell 3 ADC gain correction
#define VC3COEFF3				0x006F // Cell 3 ADC gain correction
#define VC3COEFF4				0x0070 // Cell 3 ADC gain correction
#define VC3COEFF5				0x0071 // Cell 3 ADC gain correction
#define VC3COEFF6				0x0072 // Cell 3 ADC gain correction
#define VC3COEFF7				0x0073 // Cell 3 ADC gain correction
#define VC3COEFF8				0x0074 // Cell 3 ADC gain correction
#define VC3COEFF9				0x0075 // Cell 3 ADC offset/gain correction
#define VC3COEFF10				0x0076 // Cell 3 ADC offset correction
#define VC3COEFF11				0x0077 // Cell 3 ADC offset correction
#define VC3COEFF12				0x0078 // Cell 3 ADC offset correction
#define VC3COEFF13				0x0079 // Cell 3 ADC offset correction
#define VC3COEFF14				0x007A // Cell 3 ADC offset correction
#define VC4COEFF1				0x007B // Cell 4 ADC gain correction
#define VC4COEFF2				0x007C // Cell 4 ADC gain correction
#define VC4COEFF3				0x007D // Cell 4 ADC gain correction
#define VC4COEFF4				0x007E // Cell 4 ADC gain correction
#define VC4COEFF5				0x007F // Cell 4 ADC gain correction
#define VC4COEFF6				0x0080 // Cell 4 ADC gain correction
#define VC4COEFF7				0x0081 // Cell 4 ADC gain correction
#define VC4COEFF8				0x0082 // Cell 4 ADC gain correction
#define VC4COEFF9				0x0083 // Cell 4 ADC offset/gain correction
#define VC4COEFF10				0x0084 // Cell 4 ADC offset correction
#define VC4COEFF11				0x0085 // Cell 4 ADC offset correction
#define VC4COEFF12				0x0086 // Cell 4 ADC offset correction
#define VC4COEFF13				0x0087 // Cell 4 ADC offset correction
#define VC4COEFF14				0x0088 // Cell 4 ADC offset correction
#define VC5COEFF1				0x0089 // Cell 5 ADC gain correction
#define VC5COEFF2				0x008A // Cell 5 ADC gain correction
#define VC5COEFF3				0x008B // Cell 5 ADC gain correction
#define VC5COEFF4				0x008C // Cell 5 ADC gain correction
#define VC5COEFF5				0x008D // Cell 5 ADC gain correction
#define VC5COEFF6				0x008E // Cell 5 ADC gain correction
#define VC5COEFF7				0x008F // Cell 5 ADC gain correction
#define VC5COEFF8				0x0090 // Cell 5 ADC gain correction
#define VC5COEFF9				0x0091 // Cell 5 ADC offset/gain correction
#define VC5COEFF10				0x0092 // Cell 5 ADC offset correction
#define VC5COEFF11				0x0093 // Cell 5 ADC offset correction
#define VC5COEFF12				0x0094 // Cell 5 ADC offset correction
#define VC5COEFF13				0x0095 // Cell 5 ADC offset correction
#define VC5COEFF14				0x0096 // Cell 5 ADC offset correction
#define VC6COEFF1				0x0097 // Cell 6 ADC gain correction
#define VC6COEFF2				0x0098 // Cell 6 ADC gain correction
#define VC6COEFF3				0x0099 // Cell 6 ADC gain correction
#define VC6COEFF4				0x009A // Cell 6 ADC gain correction
#define VC6COEFF5				0x009B // Cell 6 ADC gain correction
#define VC6COEFF6				0x009C // Cell 6 ADC gain correction
#define VC6COEFF7				0x009D // Cell 6 ADC gain correction
#define VC6COEFF8				0x009E // Cell 6 ADC gain correction
#define VC6COEFF9				0x009F // Cell 6 ADC offset/gain correction
#define VC6COEFF10				0x00A0 // Cell 6 ADC offset correction
#define VC6COEFF11				0x00A1 // Cell 6 ADC offset correction
#define VC6COEFF12				0x00A2 // Cell 6 ADC offset correction
#define VC6COEFF13				0x00A3 // Cell 6 ADC offset correction
#define VC6COEFF14				0x00A4 // Cell 6 ADC offset correction
#define VAUXCOEFF1				0x00A5 // GP ADC gain correction - CH2-32
#define VAUXCOEFF2				0x00A6 // GP ADC gain correction - CH2-32
#define VAUXCOEFF3				0x00A7 // GP ADC gain correction - CH2-32
#define VAUXCOEFF4				0x00A8 // GP ADC gain correction - CH2-32
#define VAUXCOEFF5				0x00A9 // GP ADC gain correction - CH2-32
#define VAUXCOEFF6				0x00AA // GP ADC gain correction - CH2-32
#define VAUXCOEFF7				0x00AB // GP ADC gain correction - CH2-32
#define VAUXCOEFF8				0x00AC // GP ADC gain correction - CH2-32
#define VAUXCOEFF9				0x00AD // GP ADC offset/gain correction - CH2-32
#define VAUXCOEFF10				0x00AE // GP ADC offset correction - CH2-32
#define VAUXCOEFF11				0x00AF // GP ADC offset correction - CH2-32
#define VAUXCOEFF12				0x00B0 // GP ADC offset correction - CH2-32
#define VAUXCOEFF13				0x00B1 // GP ADC offset correction - CH2-32
#define VAUXCOEFF14				0x00B2 // GP ADC offset correction - CH2-32                            
#define VAUXCELLCOEFF1			0x00B3 // GP ADC gain correction - CH1
#define VAUXCELLCOEFF2			0x00B4 // GP ADC gain correction - CH1
#define VAUXCELLCOEFF3			0x00B5 // GP ADC gain correction - CH1
#define VAUXCELLCOEFF4			0x00B6 // GP ADC gain correction - CH1
#define VAUXCELLCOEFF5			0x00B7 // GP ADC gain correction - CH1
#define VAUXCELLCOEFF6			0x00B8 // GP ADC gain correction - CH1
#define VAUXCELLCOEFF7			0x00B9 // GP ADC gain correction - CH1
#define VAUXCELLCOEFF8			0x00BA // GP ADC gain correction - CH1
#define VAUXCELLCOEFF9			0x00BB // GP ADC offset/gain correction - CH1
#define VAUXCELLCOEFF10			0x00BC // GP ADC offset correction - CH1
#define VAUXCELLCOEFF11			0x00BD // GP ADC offset correction - CH1
#define VAUXCELLCOEFF12			0x00BE // GP ADC offset correction - CH1
#define VAUXCELLCOEFF13			0x00BF // GP ADC offset correction - CH1
#define VAUXCELLCOEFF14			0x00C0 // GP ADC offset correction - CH1  
#define SPARE_06				0x00C1 // Spare register
#define CUST_MISC1				0x00C2 // Customer OTP memory 1
#define CUST_MISC2				0x00C3 // Customer OTP memory 2
#define CUST_MISC3				0x00C4 // Customer OTP memory 3
#define CUST_MISC4				0x00C5 // Customer OTP memory 4
#define CUST_CRCH				0x00C6 // Customer CRC high byte
#define CUST_CRCL				0x00C7 // Customer CRC low byte
#define OTP_PROG_UNLOCK1A		0x0100 // OTP program unlock code 1A
#define OTP_PROG_UNLOCK1B		0x0101 // OTP program unlock code 1B
#define OTP_PROG_UNLOCK1C		0x0102 // OTP program unlock code 1C
#define OTP_PROG_UNLOCK1D		0x0103 // OTP program unlock code 1D
#define DEVADD_USR				0x0104 // Programmable device address
#define CONTROL1				0x0105 // Device control
#define CONTROL2				0x0106 // Function enable control
#define OTP_PROG_CTRL			0x0107 // OTP programming control
#define GPIO_OUT				0x0108 // GPIO output control
#define CELL_ADC_CTRL			0x0109 // Cell ADC control
#define AUX_ADC_CTRL1			0x010A // Auxiliary ADC control 1
#define AUX_ADC_CTRL2			0x010B // Auxiliary ADC control 2
#define AUX_ADC_CTRL3			0x010C // Auxiliary ADC control 3
#define CB_CONFIG				0x010D // Balance timer configuration
#define CB_CELL1_CTRL			0x010E // Cell 1 balance timer configuration
#define CB_CELL2_CTRL			0x010F // Cell 2 balance timer configuration
#define CB_CELL3_CTRL			0x0110 // Cell 3 balance timer configuration
#define CB_CELL4_CTRL			0x0111 // Cell 4 balance timer configuration
#define CB_CELL5_CTRL			0x0112 // Cell 5 balance timer configuration
#define CB_CELL6_CTRL			0x0113 // Cell 6 balance timer configuration
#define CB_DONE_THRESHOLD		0x0114 // Cell balance done comparator threshold
#define CB_SW_EN				0x0115 // Cell balancing manual switch enable
#define DIAG_CTRL1				0x0116 // Diagnostic control register 1
#define DIAG_CTRL2				0x0117 // Diagnostic control register 2
#define DIAG_CTRL3				0x0118 // Diagnostic control register 3
#define DIAG_CTRL4				0x0119 // Diagnostic control register 4
#define VC_CS_CTRL				0x011A // VC current source/sink control
#define CB_CS_CTRL				0x011B // CB current source/sink control
#define CBVC_COMP_CTRL			0x011C // CB switch comparator control
#define ECC_TEST				0x011D // ECC test
#define ECC_DATAIN0				0x011E // 1st data in byte for manual ECC test
#define ECC_DATAIN1				0x011F // 2nd data in byte for manual ECC test
#define ECC_DATAIN2				0x0120 // 3rd data in byte for manual ECC test
#define ECC_DATAIN3				0x0121 // 4th data in byte for manual ECC test
#define ECC_DATAIN4				0x0122 // 5th data in byte for manual ECC test
#define ECC_DATAIN5				0x0123 // 6th data in byte for manual ECC test
#define ECC_DATAIN6				0x0124 // 7th data in byte for manual ECC test
#define ECC_DATAIN7				0x0125 // 8th data in byte for manual ECC test
#define ECC_DATAIN8				0x0126 // 9th data in byte for manual ECC test
#define GPIO_FLT_RST			0x0127 // GPIO fault reset
#define UV_FLT_RST				0x0128 // UV comparator fault reset
#define OV_FLT_RST				0x0129 // OV comparator fault reset
#define UT_FLT_RST				0x012A // UT comparator fault reset
#define OT_FLT_RST				0x012B // OT comparator fault reset
#define TONE_FLT_RST			0x012C // Fault bus status reset
#define COMM_UART_FLT_RST		0x012D // UART fault status reset
#define COMM_UART_RC_FLT_RST	0x012E // UART receive command fault reset
#define COMM_UART_RR_FLT_RST	0x012F // UART receive response fault reset
#define COMM_UART_TR_FLT_RST	0x0130 // UART transmit fault reset
#define COMM_COMH_FLT_RST		0x0131 // COMH bus fault reset
#define COMM_COMH_RC_FLT_RST	0x0132 // COMH bus receive command fault reset
#define COMM_COMH_RR_FLT_RST	0x0133 // COMH bus receive command fault reset
#define COMM_COMH_TR_FLT_RST	0x0134 // COMH bus transmit fault reset
#define COMM_COML_FLT_RST		0x0135 // COML bus fault reset
#define COMM_COML_RC_FLT_RST	0x0136 // COML bus receive command fault reset
#define COMM_COML_RR_FLT_RST	0x0137 // COML bus receive command fault reset
#define COMM_COML_TR_FLT_RST	0x0138 // COML bus transmit fault reset
#define OTP_FLT_RST				0x0139 // OTP page fault reset
#define RAIL_FLT_RST			0x013A // Power rail reset
#define SYSFLT1_FLT_RST			0x013B // System fault 1 reset
#define SYSFLT2_FLT_RST			0x013C // System fault 2 reset
#define SYSFLT3_FLT_RST			0x013D // IC system fault 3 reset
#define OVUV_BIST_FLT_RST		0x013E // OVUV bist fault reset
#define OTUT_BIST_FLT_RST		0x013F // OTUT bist fault reset
#define OTP_PROG_UNLOCK2A		0x0150 // OTP program unlock code 2A
#define OTP_PROG_UNLOCK2B		0x0151 // OTP program unlock code 2B
#define OTP_PROG_UNLOCK2C		0x0152 // OTP program unlock code 2C
#define OTP_PROG_UNLOCK2D		0x0153 // OTP program unlock code 2D
#define SPI_CFG					0x0154 // SPI master configuration
#define SPI_TX					0x0155 // SPI byte to transmit
#define SPI_EXE					0x0156 // SPI command execute
#define PARTID					0x0200 // Customer revision information
#define SYS_FAULT1				0x0201 // System fault 1 status
#define SYS_FAULT2				0x0202 // System fault 2 status
#define SYS_FAULT3				0x0203 // IC system fault 3 status
#define DEV_STAT				0x0204 // Device status
#define LOOP_STAT				0x0205 // Round robin status
#define FAULT_SUM				0x0206 // Fault summary
#define VCELL1_HF				0x0207 // Cell 1 voltage high byte (low pass filtered)
#define VCELL1_LF				0x0208 // Cell 1 voltage low byte (low pass filtered)
#define VCELL2_HF				0x0209 // Cell 2 voltage high byte (low pass filtered)
#define VCELL2_LF				0x020A // Cell 2 voltage low byte (low pass filtered)
#define VCELL3_HF				0x020B // Cell 3 voltage high byte (low pass filtered)
#define VCELL3_LF				0x020C // Cell 3 voltage low byte (low pass filtered)
#define VCELL4_HF				0x020D // Cell 4 voltage high byte (low pass filtered)
#define VCELL4_LF				0x020E // Cell 4 voltage low byte (low pass filtered)
#define VCELL5_HF				0x020F // Cell 5 voltage high byte (low pass filtered)
#define VCELL5_LF				0x0210 // Cell 5 voltage low byte (low pass filtered)
#define VCELL6_HF				0x0211 // Cell 6 voltage high byte (low pass filtered)
#define VCELL6_LF				0x0212 // Cell 6 voltage low byte (low pass filtered)
#define CONV_CNTH				0x0213 // Cell ADC conversion counter high byte
#define CONV_CNTL				0x0214 // Cell ADC conversion counter low byte
#define VCELL1H					0x0215 // Cell 1 voltage high byte (corrected)
#define VCELL1L					0x0216 // Cell 1 voltage low byte (corrected)
#define VCELL2H					0x0217 // Cell 2 voltage high byte (corrected)
#define VCELL2L					0x0218 // Cell 2 voltage low byte (corrected)
#define VCELL3H					0x0219 // Cell 3 voltage high byte (corrected)
#define VCELL3L					0x021A // Cell 3 voltage low byte (corrected)
#define VCELL4H					0x021B // Cell 4 voltage high byte (corrected)
#define VCELL4L					0x021C // Cell 4 voltage low byte (corrected)
#define VCELL5H					0x021D // Cell 5 voltage high byte (corrected)
#define VCELL5L					0x021E // Cell 5 voltage low byte (corrected)
#define VCELL6H					0x021F // Cell 6 voltage high byte (corrected)
#define VCELL6L					0x0220 // Cell 6 voltage low byte (corrected)                       
#define VCELL_FACTCORRH			0x0221 // Selected cell factory corrected high byte
#define VCELL_FACTCORRL			0x0222 // Selected cell factory corrected low byte                       
#define AUX_CELLH				0x0223 // AUX measurement voltage high byte
#define AUX_CELLL				0x0224 // AUX measurement voltage low byte                       
#define AUX_BATH				0x0225 // Cell stack voltage high byte (corrected)
#define AUX_BATL				0x0226 // Cell stack voltage low byte (corrected)
#define AUX_REF2H				0x0227 // Bandgap 1 measurement voltage high byte
#define AUX_REF2L				0x0228 // Bandgap 1 measurement voltage low byte                       
#define AUX_ZEROH				0x0229 // ZERO reference voltage high byte
#define AUX_ZEROL				0x022A // ZERO reference voltage low byte                       
#define AUX_AVDDH				0x022B // AVDD LDO voltage output high byte
#define AUX_AVDDL				0x022C // AVDD LDO voltage output low byte             
#define AUX_GPIO1H				0x022D // GPIO1 voltage high byte (corrected)
#define AUX_GPIO1L				0x022E // GPIO1 voltage low byte (corrected)
#define AUX_GPIO2H				0x022F // GPIO2 voltage high byte (corrected)
#define AUX_GPIO2L				0x0230 // GPIO2 voltage low byte (corrected)
#define AUX_GPIO3H				0x0231 // GPIO3 voltage high byte (corrected)
#define AUX_GPIO3L				0x0232 // GPIO3 voltage low byte (corrected)
#define AUX_GPIO4H				0x0233 // GPIO4 voltage high byte (corrected)
#define AUX_GPIO4L				0x0234 // GPIO4 voltage low byte (corrected)
#define AUX_GPIO5H				0x0235 // GPIO5 voltage high byte (corrected)
#define AUX_GPIO5L				0x0236 // GPIO5 voltage low byte (corrected)
#define AUX_GPIO6H				0x0237 // GPIO6 voltage high byte (corrected)
#define AUX_GPIO6L				0x0238 // GPIO6 voltage low byte (corrected)
#define AUX_FACTCORRH			0x0239 // Selected GPIO factory corrected high byte
#define AUX_FACTCORRL			0x023A // Selected GPIO factory corrected low byte                       
#define DIE_TEMPH				0x023B // Die junction temperature high byte                       
#define DIE_TEMPL				0x023C // Die junction temperature low byte                       
#define AUX_REF3H				0x023D // Bandgap 2 voltage output high byte                       
#define AUX_REF3L				0x023E // Bandgap 2 voltage output low byte                       
#define AUX_OV_DACH				0x023F // OV reference voltage high byte                       
#define AUX_OV_DACL				0x0240 // OV reference voltage low byte                       
#define AUX_UV_DACH				0x0241 // UV reference voltage high byte                       
#define AUX_UV_DACL				0x0242 // UV reference voltage low byte                       
#define AUX_OT_DACH				0x0243 // OT reference voltage high byte                       
#define AUX_OT_DACL				0x0244 // OT reference voltage low byte                       
#define AUX_UT_DACH				0x0245 // UT reference voltage high byte                       
#define AUX_UT_DACL				0x0246 // UT reference voltage low byte                       
#define AUX_TWARN_PTATH			0x0247 // TWARN PTAT current high byte                       
#define AUX_TWARN_PTATL			0x0248 // TWARN PTAT current low byte                       
#define AUX_DVDDH				0x0249 // DVDD LDO voltage output high byte
#define AUX_DVDDL				0x024A // DVDD LDO voltage output low byte             
#define AUX_TSREFH				0x024B // TSREF voltage output high byte
#define AUX_TSREFL				0x024C // TSREF voltage output low byte             
#define AUX_CVDDH				0x024D // CVDD LDO voltage output high byte
#define AUX_CVDDL				0x024E // CVDD LDO voltage output low byte             
#define AUX_AVAOH				0x024F // AVAO reference voltage output high byte
#define AUX_AVAOL				0x0250 // AVAO reference voltage output low byte             
#define SPI_RX					0x0260 // SPI byte read
#define CB_DONE					0x0261 // Cell balancing complete status
#define GPIO_STAT				0x0262 // GPIO input status
#define CBVC_COMP_STAT			0x0263 // CBVC comparator status
#define CBVC_VCLOW_STAT			0x0264 // CBVC VCLOW comparator status
#define COMM_UART_RC_STAT3		0x0265 // Discarded UART command frame counter
#define COMM_COML_RC_STAT3		0x0266 // Discarded COML command frame counter
#define COMM_COMH_RR_STAT3		0x0267 // Discarded COMH response frame counter
#define COMM_COML_RR_STAT3		0x0268 // Discarded COML response frame counter
#define COMM_COMH_RC_STAT3		0x0269 // Discarded COMH command frame counter
#define COMM_UART_RR_STAT3		0x026A // Discarded UART response frame counter
#define COMM_UART_RC_STAT1		0x026B // Valid UART command frame counter high byte
#define COMM_UART_RC_STAT2		0x026C // Valid UART command frame counter low byte
#define COMM_COML_RC_STAT1		0x026D // Valid COML command frame counter high byte
#define COMM_COML_RC_STAT2		0x026E // Valid COML command frame counter low byte
#define COMM_COMH_RR_STAT1		0x026F // Valid COMH response frame counter high byte
#define COMM_COMH_RR_STAT2		0x0270 // Valid COMH response frame counter low byte
#define COMM_UART_TR_STAT1		0x0271 // Transmitted UART response frame counter high byte
#define COMM_UART_TR_STAT2		0x0272 // Transmitted UART response frame counter low byte
#define COMM_COML_TR_STAT1		0x0273 // Transmitted COML response frame counter high byte
#define COMM_COML_TR_STAT2		0x0274 // Transmitted COML response frame counter low byte
#define COMM_COMH_RC_STAT1		0x0275 // Valid COMH command frame counter high byte
#define COMM_COMH_RC_STAT2		0x0276 // Valid COMH command frame counter low byte
#define COMM_COML_RR_STAT1		0x0277 // Valid COML response frame counter high byte
#define COMM_COML_RR_STAT2		0x0278 // Valid COML response frame counter low byte
#define COMM_COMH_TR_STAT1		0x0279 // Transmitted COMH response frame counter high byte
#define COMM_COMH_TR_STAT2		0x027A // Transmitted COMH response frame counter low byte
#define COMM_UART_RR_STAT1		0x027B // Valid UART response frame counter high byte
#define COMM_UART_RR_STAT2		0x027C // Valid UART response frame counter low byte
#define OTP_PROG_STAT			0x027D // OTP programming status
#define OTP_CUST1_STAT1			0x027E // Customer OTP page 1 status
#define OTP_CUST1_STAT2			0x027F // Customer OTP page 2 programming status
#define OTP_CUST2_STAT1			0x0280 // Customer OTP page 1 status
#define OTP_CUST2_STAT2			0x0281 // Customer OTP page 2 programming status
#define CB_SW_STAT				0x0282 // Cell balancing switch status
#define GPIO_FAULT				0x0290 // GPIO fault status
#define UV_FAULT				0x0291 // UV comparator fault status
#define OV_FAULT				0x0292 // OV comparator fault status
#define UT_FAULT				0x0293 // UT comparator fault status
#define OT_FAULT				0x0294 // OT comparator fault status
#define TONE_FAULT				0x0295 // Fault bus status
#define COMM_UART_FAULT			0x0296 // UART fault status
#define COMM_UART_RC_FAULT		0x0297 // UART receive command fault status
#define COMM_UART_RR_FAULT		0x0298 // UART receive response fault status (only valid in multidrop mode)
#define COMM_UART_TR_FAULT		0x0299 // UART transmit fault status 
#define COMM_COMH_FAULT			0x029A // COMH fault status
#define COMM_COMH_RC_FAULT		0x029B // COMH receive command fault status
#define COMM_COMH_RR_FAULT		0x029C // COMH receive response fault status 
#define COMM_COMH_TR_FAULT		0x029D // COMH transmit fault status 
#define COMM_COML_FAULT			0x029E // COML fault status
#define COMM_COML_RC_FAULT		0x029F // COML receive command fault status
#define COMM_COML_RR_FAULT		0x02A0 // COML receive response fault status 
#define COMM_COML_TR_FAULT		0x02A1 // COML transmit fault status 
#define OTP_FAULT				0x02A2 // OTP page fault status
#define RAIL_FAULT				0x02A3 // Power rail fault status
#define OVUV_BIST_FAULT			0x02A4 // OVUV BIST fault status
#define OTUT_BIST_FAULT			0x02A5 // OTUT BIST fault status
#define ECC_DATAOUT0			0x02B0 // 1st data out byte for ECC test
#define ECC_DATAOUT1			0x02B1 // 2nd data out byte for ECC test
#define ECC_DATAOUT2			0x02B2 // 3rd data out byte for ECC test
#define ECC_DATAOUT3			0x02B3 // 4th data out byte for ECC test
#define ECC_DATAOUT4			0x02B4 // 5th data out byte for ECC test
#define ECC_DATAOUT5			0x02B5 // 6th data out byte for ECC test
#define ECC_DATAOUT6			0x02B6 // 7th data out byte for ECC test
#define ECC_DATAOUT7			0x02B7 // 8th data out byte for ECC test
#define ECC_DATAOUT8			0x02B8 // 9th data out byte for ECC test
#define SEC_BLK					0x02B9 // SEC detected block
#define DED_BLK					0x02BA // DED detected block
#define DEV_ADD_STAT			0x02BB // Device address status
#define COMM_STAT				0x02BC // Communication status register
#define DAISY_CHAIN_STAT		0x02BD // Communication status register
#define VCELL1_HU				0x02C0 // Cell 1 voltage high byte (uncorrected)
#define VCELL1_MU				0x02C1 // Cell 1 voltage middle byte (uncorrected)
#define VCELL1_LU				0x02C2 // Cell 1 voltage low byte (uncorrected)
#define VCELL2_HU				0x02C3 // Cell 2 voltage high byte (uncorrected)
#define VCELL2_MU				0x02C4 // Cell 2 voltage middle byte (uncorrected)
#define VCELL2_LU				0x02C5 // Cell 2 voltage low byte (uncorrected)
#define VCELL3_HU				0x02C6 // Cell 3 voltage high byte (uncorrected)
#define VCELL3_MU				0x02C7 // Cell 3 voltage middle byte (uncorrected)
#define VCELL3_LU				0x02C8 // Cell 3 voltage low byte (uncorrected)
#define VCELL4_HU				0x02C9 // Cell 4 voltage high byte (uncorrected)
#define VCELL4_MU				0x02CA // Cell 4 voltage middle byte (uncorrected)
#define VCELL4_LU				0x02CB // Cell 4 voltage low byte (uncorrected)
#define VCELL5_HU				0x02CC // Cell 5 voltage high byte (uncorrected)
#define VCELL5_MU				0x02CD // Cell 5 voltage middle byte (uncorrected)
#define VCELL5_LU				0x02CE // Cell 5 voltage low byte (uncorrected)
#define VCELL6_HU				0x02CF // Cell 6 voltage high byte (uncorrected)
#define VCELL6_MU				0x02D0 // Cell 6 voltage middle byte (uncorrected)
#define VCELL6_LU				0x02D1 // Cell 6 voltage low byte (uncorrected)
#define AUX_BAT_HU				0x02D2 // Cell stack voltage high byte (uncorrected)
#define AUX_BAT_LU				0x02D3 // Cell stack voltage low byte (uncorrected)
#define AUX_GPIO1_HU			0x02D4 // GPIO1 voltage high byte (uncorrected)
#define AUX_GPIO1_MU			0x02D5 // GPIO1 voltage middle byte (uncorrected)
#define AUX_GPIO1_LU			0x02D6 // GPIO1 voltage low byte (uncorrected)
#define AUX_GPIO2_HU			0x02D7 // GPIO2 voltage high byte (uncorrected)
#define AUX_GPIO2_LU			0x02D8 // GPIO2 voltage low byte (uncorrected)
#define AUX_GPIO3_HU			0x02D9 // GPIO3 voltage high byte (uncorrected)
#define AUX_GPIO3_LU			0x02DA // GPIO3 voltage low byte (uncorrected)
#define AUX_GPIO4_HU			0x02DB // GPIO4 voltage high byte (uncorrected)
#define AUX_GPIO4_LU			0x02DC // GPIO4 voltage low byte (uncorrected)
#define AUX_GPIO5_HU			0x02DD // GPIO5 voltage high byte (uncorrected)
#define AUX_GPIO5_LU			0x02DE // GPIO5 voltage low byte (uncorrected)
#define AUX_GPIO6_HU			0x02DF // GPIO6 voltage high byte (uncorrected)
#define AUX_GPIO6_LU			0x02E0 // GPIO6 voltage low byte (uncorrected)
#define CUST_CRC_RSLTH			0x02E1 // Calculated customer CRC result high byte                                    
#define CUST_CRC_RSLTL			0x02E2 // Calculated customer CRC result low byte


// Function Prototypes
void Wake79606();
void Ini_ESP();
void InitDevices();
void CommClear(void);
void CommSleepToWake(void);
void CommReset(void);
void AutoAddress(void);
bool GetFaultStat();

float Complement(uint16_t rawData, float multiplier);

uint16_t CRC16(byte *pBuf, int nLen);

int  WriteReg(byte bID, uint16_t wAddr, uint64_t dwData, byte bLen, byte bWriteType);
int  ReadReg(byte bID, uint16_t wAddr, byte * pData, byte bLen, uint32_t dwTimeOut, byte bWriteType);

int  WriteFrame(byte bID, uint16_t wAddr, byte * pData, byte bLen, byte bWriteType);
int  ReadFrameReq(byte bID, uint16_t wAddr, byte bByteToReturn,byte bWriteType);


#endif