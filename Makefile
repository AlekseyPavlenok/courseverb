DIR_BIN = ./bin
DIR_BUILD_SRC = ./build/src
DIR_BIILD_TEST = ./build/test
DIR_SRC = ./src
CFLAGS = -std=gnu11 -Wall -Werror

.PHONY: clean test FORMAT all 

all: $(DIR_BIN)/main
	make FORMAT
test: $(DIR_BIN)/test
	$(DIR_BIN)/test

-include build/src/*.d

$(DIR_BIN)/main: $(DIR_BUILD_SRC)/main.o $(DIR_BUILD_SRC)/develop.o $(DIR_BUILD_SRC)/menu.o $(DIR_BUILD_SRC)/table.o $(DIR_BUILD_SRC)/test1.o $(DIR_BUILD_SRC)/test2.o
	gcc -Wall -Werror -o $(DIR_BIN)/main $(DIR_BUILD_SRC)/main.o $(DIR_BUILD_SRC)/develop.o $(DIR_BUILD_SRC)/menu.o $(DIR_BUILD_SRC)/table.o $(DIR_BUILD_SRC)/test1.o $(DIR_BUILD_SRC)/test2.o
$(DIR_BUILD_SRC)/main.o: $(DIR_SRC)/main.c
	gcc -Wall -Werror -o $(DIR_BUILD_SRC)/main.o -c $(DIR_SRC)/main.c
$(DIR_BUILD_SRC)/develop.o: $(DIR_SRC)/develop.c
	gcc -Wall -Werror -o $(DIR_BUILD_SRC)/develop.o -c $(DIR_SRC)/develop.c
$(DIR_BUILD_SRC)/menu.o: $(DIR_SRC)/menu.c    
	gcc -Wall -Werror -o $(DIR_BUILD_SRC)/menu.o -c $(DIR_SRC)/menu.c
$(DIR_BUILD_SRC)/check.o: $(DIR_SRC)/check.c    
	gcc -Wall -Werror -o $(DIR_BUILD_SRC)/check.o -c $(DIR_SRC)/check.c
$(DIR_BUILD_SRC)/table.o: $(DIR_SRC)/table.c    
	gcc -Wall -Werror -o $(DIR_BUILD_SRC)/table.o -c $(DIR_SRC)/table.c
$(DIR_BUILD_SRC)/test1.o: $(DIR_SRC)/test1.c    
	gcc -Wall -Werror -o $(DIR_BUILD_SRC)/test1.o -c $(DIR_SRC)/test1.c
$(DIR_BUILD_SRC)/test2.o: $(DIR_SRC)/test2.c    
	gcc -Wall -Werror -o $(DIR_BUILD_SRC)/test2.o -c $(DIR_SRC)/test2.c

-include build/test/*.d

bin/test: build/test/main.o build/test/menu.o build/test/table.o build/test/test1.o build/test/test2.o build/test/develop.o build/test/tests.o
	gcc $(CFLAGS) -o $@ $^

build/test/main.o: test/main.c
	gcc -I thirdparty -I src $(CFLAGS) -MMD -c -o $@ $<

build/test/menu.o: src/menu.c
	gcc -I thirdparty -I src $(CFLAGS) -MMD -c -o $@ $<

build/test/tests.o: test/tests.c
	gcc -I thirdparty -I src $(CFLAGS) -MMD -c -o $@ $<

build/test/table.o: src/table.c
	gcc -I thirdparty -I src $(CFLAGS) -MMD -c -o $@ $<

build/test/test1.o: src/test1.c
	gcc -I thirdparty -I src $(CFLAGS) -MMD -c -o $@ $<

build/test/test2.o: src/test2.c
	gcc -I thirdparty -I src $(CFLAGS) -MMD -c -o $@ $<

build/test/develop.o: src/develop.c
	gcc -I thirdparty -I src $(CFLAGS) -MMD -c -o $@ $<

clean:
	rm -rf build/src/*.o build/src/*.d build/test/*.o build/test/*.d bin/*

FORMAT:
	clang-format -i $(DIR_SRC)/*.h
	clang-format -i $(DIR_SRC)/*.c
	clang-format -i ./test/*.c
	
