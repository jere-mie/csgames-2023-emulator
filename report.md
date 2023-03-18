# CSGames-Émulateur-2023

## Team

"Loop Troops" (University of Windsor Team A)

### Members

- Jeremie Bornais
- Justin Bornais

## Part 1 - Get the 6502 Emulator Working

### Summary

We implemented the two functions `read6502` and `write6502` by simply using an array to represent the CPU's memory, and retrieving/setting the value at a specific part of memory based on the parameters. We made an additional change to `write6502`, whereby we keep track of how many times the address `0xFFF1` is written to. Once it has been written to 48 times, we know the prophecy has been revealed (or not).

### Results

- Encryption Key: `808`
- Prophecy: `"640K OUGHT TO BE ENOUGH FOR ANYONE." -- B.GATES`

### How to Run

Simply type `make` and the program will compile and run! If you just want to compile, you can run `make compile`, and if you want to clean, run `make clean`

## Part 2 - Understand How the Mythical 6502 Emulator Works

### Instruction Set

The instruction set of the 6502 emulator is implemented using simple C functions that emulate how each instruction should work. For example, `and`, `brk`, `inc`, etc. all have C functions that emulate the behaviour of each instruction.

### Opcodes & Addrtable

The different opcodes and the address table are implemented using arrays of function pointers. For example, opcode 0x21 represents the `and` instruction, and thus `optable[0x11]` stores a function pointer to the `and` C function which emulates the behaviour of the 6502's `and` instruction.

### Memory

The way we implemented memory is by using a simple array of bytes of length 65536 (for 64kb of RAM). Each element corresponds to a byte of memory in the emulated RAM.

#### Reading From and Writing to Memory

We implemented the `read6502` and `write6502` functions to allow for reading from and writing to memory. `read6502` simply takes in a memory address location, and returns the byte in the memory array that corresponds to the emulated address location. `write6502` does something similar - taking in an address and setting the value of the array element with the provided parameter.

### Running the Emulator

There are two ways to run the emulator - `exec6502` and `step6502`. These two functions simply fetch the next instruction from memory and execute it (by using the optable and addrtable and associated C functions). The difference is, `exec6502` will run for a specified max number of clock ticks (executing multiple instructions), whereas `step6502` will only run one instruction.

## Part 2 - Understand How the Mythical 6502 Emulator Works

### Instruction Set

The instruction set of the 6502 emulator is implemented using simple C functions that emulate how each instruction should work. For example, `and`, `brk`, `inc`, etc. all have C functions that emulate the behaviour of each instruction.

### Opcodes & Addrtable

The different opcodes and the address table are implemented using arrays of function pointers. For example, opcode 0x21 represents the `and` instruction, and thus `optable[0x11]` stores a function pointer to the `and` C function which emulates the behaviour of the 6502's `and` instruction.

### Memory

The way we implemented memory is by using a simple array of bytes of length 65536 (for 64kb of RAM). Each element corresponds to a byte of memory in the emulated RAM.

#### Reading From and Writing to Memory

We implemented the `read6502` and `write6502` functions to allow for reading from and writing to memory. `read6502` simply takes in a memory address location, and returns the byte in the memory array that corresponds to the emulated address location. `write6502` does something similar - taking in an address and setting the value of the array element with the provided parameter.

### Running the Emulator

There are two ways to run the emulator - `exec6502` and `step6502`. These two functions simply fetch the next instruction from memory and execute it (by using the optable and addrtable and associated C functions). The difference is, `exec6502` will run for a specified max number of clock ticks (executing multiple instructions), whereas `step6502` will only run one instruction.
