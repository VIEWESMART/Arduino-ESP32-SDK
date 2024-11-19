# Arduino-ESP32-SDK

### This repository is an SDK that provides better performance of the esp32 development board for developers using the Arduino IDE. It is a complete development board SDK that has been adapted to solve the screen drift problem caused by developers using the ESP32 S3 to drive the RGB screen. 

## HOW to Use?
To use the SDKs from this repository in the Arduino IDE, follow these steps:
* download the released SDKs from this repository and replace the corresponding packages in the arduino-esp32 SDK:
	* Step: Find the default root path of the arduino-esp32 SDK. It should be different for different operating systems:
		* For Windows, the default path is `C:\Users\<user name>\AppData\Local\Arduino15\packages\esp32`.
		* For Linux, the default path is `~/.arduino15/packages/esp32`.


## Why do I get drift (overall drift of the display) when ESP32-S3 is driving an RGB LCD screen?
* Reasons

	* The PCLK setting of the RGB peripheral is too high, and the bandwidth of PSRAM or GDMA cannot be satisfied.

	* PSRAM and flash share a set of SPI interfaces. PSRAM is disabled during writes to flash (such as via Wi-Fi, OTA, Bluetooth LE).

	* Reading a large amount of flash/PSRAM data results in insufficient PSRAM bandwidth.

* Solutions

	* Improve PSRAM and flash bandwidth. For example, use a higher frequency or larger bit width under the conditions allowed by the hardware.

	* Enable `CONFIG_COMPILER_OPTIMIZATION_PERF`.

	* Reduce the Data Cache Line Size to 32 Bytes (set to 64 Bytes when using the RGB `Bounce Buffer` mode).

	* Enable `CONFIG_SPIRAM_FETCH_INSTRUCTIONS` and `CONFIG_SPIRAM_RODATA`.

	* (Not Recommended) Enable `CONFIG_LCD_RGB_RESTART_IN_VSYNC` to automatically recover after screen drifting, but this cannot completely avoid the issue and may reduce the frame rate.

* Applications

	* While ensuring the screen display is normal, try to reduce the frequency of PCLK and decrease the bandwidth utilization of PSRAM.

	* If you need to use Wi-Fi, Bluetooth LE, and continuous flash writing operations, please adopt the `XIP on PSRAM + RGB Bounce buffer` method. Here, `XIP on PSRAM` is used to load the code segment and read-only segment data into PSRAM, and the flash writing operation will not disable PSRAM after it is turned on. `RGB Bounce buffer` is used to block the frame buffer data and transfer it from PSRAM to SRAM through the CPU, and then use GDMA to transfer data to the RGB peripheral. Compared with directly using PSRAM GDMA, it can achieve higher transmission bandwidth. The setup steps are as follows:

		* Make sure the ESP-IDF version is release/v5.0 or newer (released after 2022.12.12), as older versions do not support the `XIP on PSRAM` function. (release/v4.4 supports this function through patching, but it is not recommended)

		* Confirm whether `CONFIG_SPIRAM_FETCH_INSTRUCTIONS` and `CONFIG_SPIRAM_RODATA` can be enabled in the PSRAM configuration. If the read-only data segment is too large (such as a large number of images), it may cause insufficient PSRAM space. At this time, you can use the file system or make the images into a bin to load into the designated partition.

		* Check if there is any memory (SRAM) left, and it takes about [10 * screen_width * 4] bytes.

		* Set `Data cache line size` to 64 Bytes (you can set `Data cache size` to 32 KB to save memory).

		* Set `CONFIG_FREERTOS_HZ` to 1000。

		* If all the above conditions are met, you can refer to the documentation to modify the RGB driver to `Bounce buffer` mode. The `Bounce buffer` mode allocates a block of SRAM memory as an intermediate cache, then quickly transfers the frame buffer data in blocks to SRAM via the CPU, and then transfers the data to the RGB peripheral via GDMA, thus avoiding the issue of PSRAM being disabled. If drift still occurs after enabling, you can try to increase the buffer, but this will consume more SRAM memory.

		* If you still have the drift problem when dealing with Wi-Fi, you can try to turn off `CONFIG_SPIRAM_TRY_ALLOCATE_WIFI_LWIP` in PSRAM, which takes up much SRAM space.

		* The effects of this setting include higher CPU usage, possible interrupt watchdog reset, and higher memory overhead.

		* Since the Bounce Buffer transfers data from PSRAM to SRAM through the CPU in GDMA interrupts, the program should avoid performing operations that disable interrupts for an extended period (such as calling `portENTER_CRITICAL()`), as it can still result in screen drifting.

	* For the drift caused by short-term operations of flash, such as before and after Wi-Fi connection, you can call `esp_lcd_rgb_panel_set_pclk()` before the operation to reduce the PCLK (such as 6 MHz) and delay about 20 ms (the time for RGB to complete one frame), and then increase PCLK to the original level after the operation. This operation may cause the screen to flash blank in a short-term.

	* If unavoidable, you can enable `CONFIG_LCD_RGB_RESTART_IN_VSYNC` or use the `esp_lcd_rgb_panel_restart()` to reset the RGB timing to prevent permanent drifting.

