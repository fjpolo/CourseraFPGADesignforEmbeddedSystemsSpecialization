Arrow Electronics
MAX1000 Nios II User Guide Project Files

All the files required for the MAX1000 Nios II Lab:

nios_lab_top.vhd    : 	Top Level Entity of the project - Instatating components and making the required connections
			To be completed by the user after creating the Nios Qsys.
RESET_GEN           : 	Reset Component based on Arrow Bemicro workshop
			Accepts two reset input signals (one from MAX1000 Button and one from "locked conduit" signal from PLL)
			and outputs a reset signal for the nios system.
nios_lab_top.qsf    : 	Board pin connections
nios_lab_top.sdc    :	User constraints of the project
main.c		    :	Main .c file for the Nios II Eclipse IDE. Completed and fully functional code for data request of the LIS3DH
			and LED reaction to the received y-axis data.