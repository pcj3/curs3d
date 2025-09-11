CC 			:= gcc
TARGET_EXEC := test
BUILD_DIR 	:= build
SRC_DIR 	:= src
SRCS 		:= $(shell find $(SRC_DIR) -name '*.c')
OBJS 		:= $(SRCS:%=$(BUILD_DIR)/%.o)
INC_DIRS 	:= $(shell find $(SRC_DIR) -type d)
INC_FLAGS 	:= $(addprefix -I,$(INC_DIRS))
CPPFLAGS	:= $(INC_FLAGS)
CFLAGS		:= -Wall -Wextra
LDFLAGS		:= -lncurses -lm


$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -D_XOPEN_SOURCE_EXTENDED -c $< -o $@

debug: $(OBJS)
	$(CC) $(OBJS) -g -o $@ $(LDFLAGS)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
	rm -rf ./$(TARGET_EXEC)

run :
	make clean
	make $(TARGET_EXEC)
	./$(TARGET_EXEC)