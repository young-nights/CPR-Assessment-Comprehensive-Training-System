2025-08-22 10:57:59 星期五
# 外部SRAM（SPI）的使用
-  场景1：把LVGL管理的内存空间放到外部SRAM
	**核心目标**
	**让 LVGL 的动态内存（lv_mem_alloc）全部落到外挂 23LC1024 SRAM 中，而不是 STM32 内部RAM**




