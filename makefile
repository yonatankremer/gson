OBJ = arg gsonHandler main errorHandler tokenizer

OBJ_ = arg gsonHandler main
ERR_H = errorHandling/errorHandler
TKN = tokenization/tokenizer

# Rule 1: Compile all .c files into .o files and put them in objectFiles/
all:
	clang -c $(addsuffix .c, $(OBJ_))
	clang -c $(addsuffix .c, $(ERR_H))
	clang -c $(addsuffix .c, $(TKN))
	mv *.o objectFiles/

# Rule 2: Compile main.c and put the executable in bin/
link:
	clang $(addprefix objectFiles/, $(addsuffix .o, $(OBJ))) -o bin/main

allinkr:
	make all
	make link
	make run_rio

run_rio:
	bin/./main rio.gson


# Rule 3: Clean all .o files
clean:
	rm -f objectFiles/*.o
