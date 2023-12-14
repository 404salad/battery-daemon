main: background-battery.c
	gcc background-battery.c -o background-battery $$(pkg-config --cflags --libs gtk+-3.0)

