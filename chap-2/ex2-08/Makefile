PROJECT_NAME = ex2-08
TARGET = $(PROJECT_NAME)
SRC_DIR = $(PWD)
INC_DIR = $(PWD)

SRC_FILES = $(wildcard $(SRC_DIR)*.c)

SRC_FILES += main.c  

INCLUDES = -I $(INC_DIR) 

CC = gcc
CFLAGS += -Wall
CC_SIZE=size

C_OBJS = $(SRC_FILES:.c=.o)
ALL_OBJS = $(C_OBJS)

all: $(TARGET) size 
$(C_OBJS): %.o: %.c
$(ALL_OBJS):
	@echo "[CC] $@"
	@$(CC) $(CFLAGS) -c $< -o $@	
$(TARGET): $(ALL_OBJS)
	@echo "[LD] $@"
	@$(CC)  $(ALL_OBJS) $(LIBS) $(USR_LIBS)-o $@
	@rm -f $(ALL_OBJS)
size:
	@$(CC_SIZE) -G $(TARGET) 
clean:
	rm -vf $(ALL_OBJS) $(TARGET)
