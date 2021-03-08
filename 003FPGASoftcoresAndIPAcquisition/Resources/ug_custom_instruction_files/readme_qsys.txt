Custom Instruction User Guide - readme.txt

This file contains the following sections:

o  Tool Requirements
o  Project Directory Names
o  Quartus II Project Setup
o  Nios II Software Build Flow


Tool Requirements
=============

The design used in this user guide requires the following:

- Quartus II software version 15.1 or later
- Nios II Embedded Design Suite version 15.1 or later
- IP Design Suite version 15.1 or later
- Modelsim-Altera tool version 6.4g or later (if you wish to simulate
  the design)

Please contact your local sales representative if you do not have one of these
software tools.


Project Directory Names
=================

These files are created on your local harddrive when you extract ciug_de_qsys.zip.

[ciug_de_qsys]
|----[crc_hw]
      |----CRC_Component.v
      |----CRC_Custom_Instruction.v
|----[crc_sw]
      |----[app]
            |----create-this-app
            |----[src]
                  |----ci_crc.c
                  |----crc.c
                  |----crc_main.c
                  |----ci_crc.h
                  |----crc.h
     |----[bsp]
           |----create-this-bsp
|---- Quartus II project files (.qpf, .qsf, .v, .qsys, .sopcinfo)

Quartus II Project Setup
=================

These steps will guide you in opening the Quartus II project.

1. Extract the ciug_de_qsys.zip archive file to your local harddrive. This location is referred to as <project_dir>.

2. Open the Quartus II software.

3. On the File menu, click Open Project.

4. Browse to <project_dir>. Select the  niosii_3c25_design.qpf file and click Open.

You are now ready to create a new custom instruction for the system. Refer to the Custom 
Instruction User Guide for step-by-step instructions.


Nios II Software Build Flow
====================

These steps will guide you through building the software example.

1. Open a Nios II command shell and change directory to <project_dir>.

2. Configure the FPGA by running the following command:
     nios2-configure-sof niosii_3c25_design.sof

3. After configuration completes, change the directory to:
     <project_dir>/crc_sw/app

4. Run the following command for building the application software project:
     ./create-this-app

5. When the command completes, run the application with the command:
     nios2-download -g crc.elf && nios2-terminal


Last updated October 2015
Copyright © 2011 Altera Corporation. All rights reserved.
