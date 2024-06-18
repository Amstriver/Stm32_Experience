# Stm32_Experience
# Author：CQUT_WenJie
# Describe：这是在整个学习STM32过程中遇到的问题，和各个模块的代码移植和调试。有需要的朋友可以自取！
#           （本人在初学时 自己搭建平衡小车，主控STM32F407VET6，使用STM32CubeMX进行配置的）

#Date:2024.6.18
#MPU6050代码移植(具体代码见MPU6050)
#Describe：代码中已经是我编译过的，需要进行以下操作：
1、首先在CubeMX中去配置对应的引脚i2c对应MPU6050上的引脚，VCC接3.3，GND
2、生成代码，下载打开文件MPU6050，将对应的代码Copy到相应的文件夹内。（.h文件放在./Core/Inc;.c文件放在./Core/Src）注：i2c.h和i2c.c可以不同Copy过去，因为上一步已经配置生成了这些代码
3、接着需要把i2c.c中 USER CODE BEGIN 1 --- USER CODE END 1 中的代码Copy到生成的i2c.c代码中；同时i2c.h中 USER CODE BEGIN Includes --- USER CODE END Includes 也Copy到生成的i2c.h中。
4、接着编译、下载就搞定了
注：如果芯片使用的不与我使用的一样。那么请修改mpu6050.c、inv_mpu.h中的芯片头文件"stm32f4xx_hal.h";（如果出现Error 显示为未找到stm32f4xx_hal.h等问题，请将inv_mpu.h和mpu6050.h中的 "#infdef _xxx_ 和 #endif"删掉）

