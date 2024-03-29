// 201503120 Jun Young Park
// 170411 - Quiz 1

// Definition of GPIO Registers
#define GPDR1 (*(volatile int *)0x40e00010) // General Purpose Direction Register 1 (GPIO52)
#define GPCR1 (*(volatile int *)0x40e00028) // GP Clear 1
#define GPSR1 (*(volatile int *)0x40e0001c) // GP Set 1
#define GPDR2 (*(volatile int *)0x40e00014) // GP Direction 2 (GPIO82)
#define GPCR2 (*(volatile int *)0x40e0002c) // GP Clear 2
#define GPSR2 (*(volatile int *)0x40e00020) // GP Set 2

#define GPLR1 (*(volatile int *)0x40e00004) // GP Load 1 (GPIO53)
#define GPLR2 (*(volatile int *)0x40e00008) // GP Load 2 (GPIO83)

#define CCCR (*(volatile int *)0x41300000) 
#define MDREFR (*(volatile int *)0x048000004)

#define GEDR1 (*(volatile int *)0x40e0004c) // GP Edge Detection
#define GRER1 (*(volatile int *)0x40e00034) // GP Rising Edge
#define GFER1 (*(volatile int *)0x40e00040) // GP Falling Edge

// Numeric definition for LED Control
#define BLK 2
#define ON 1
#define OFF 0

// Numeric definition for Switch level detection
#define BOTH 3
#define SW2 2
#define SW1 1
#define NP 0

// Definition of reading from GPLR registers. 
#define SW1_STAT (!((GPLR1) & (0x00200000))) // 
#define SW2_STAT (!((GPLR2) & (0x00080000))) //
#define INT_SW 1

// External functions
extern void vinit(void); // To initialize device

// Definition of functions
int IS_SW_PRESSED(void); // Return integer value by SW
int LED_Control(int CTL,int N); // LED control and It return INT_SW(1) when It detected interrupt(while delay)
void INIT_DEVICE(void); // Initialize device (Set Direction, LED Initialize)
void Set_Clock(int n); // Set clock frequency ( Range : 2~6 )