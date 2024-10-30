main:
	gcc -Wall -Wextra -o main main.c -Iinclude -Llib -lraylib -lgdi32 -lwinmm -lm -lpthread
	./main
	rm main.exe
gimple:
	gcc -fdump-tree-gimple main.c -Iinclude -Llib -lraylib -lgdi32 -lwinmm -lm -lpthread
rtl:
	gcc -fdump-rtl-all main.c -Iinclude -Llib -lraylib -lgdi32 -lwinmm -lm -lpthread
