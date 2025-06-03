USE work.dp32_types.ALL, work.alu_32_types.ALL;
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
ENTITY memory IS
	GENERIC (Tpd : TIME := unit_delay);
	PORT (
		d_bus : INOUT bus_bit_32 BUS;
		a_bus : IN bit_32;
		read : IN STD_LOGIC;
		write : IN STD_LOGIC;
		ready : OUT STD_LOGIC);
END memory;
ARCHITECTURE behaviour OF memory IS
BEGIN
	PROCESS
		CONSTANT low_address : INTEGER := 0;
		CONSTANT high_address : INTEGER := 65535;
		TYPE memory_array IS
		ARRAY(INTEGER RANGE low_address TO high_address)OF bit_32;
		VARIABLE address : INTEGER := 0;
		VARIABLE mem : memory_array :=
		(-- initializing
	-- r6 - array offset - const
	-- r5 - recurse Depth = 0 in the beginning
	-- r4 - stack pointer
	-- r0 = 0 - ALWAYS
	X"1006_0061", -- r6 - array offset
	X"1004_006C", -- r4 - stack pointer
-- QuickSort //stack: retAddr(firstcall?), low, high, pivot
	-- if (low >= high)
		X"3001_04FE", -- load r1 <- low
		X"3002_04FF", -- load r2 <- high
		X"0101_0102", -- r1 <- low(r1)-high(r2)
		X"410A_0000", -- low-high<0 then jump
		X"0000_000F", -- displacement 1
	-- if (recCount == 0)
		X"1105_0500", -- r5 <- r5-0
		X"4109_004F", -- recDepth == 0 then jump to the END OF PROGRAM
	-- sp -= 3
		X"1104_0403", -- r4 <- r4-3
	-- return
		X"3001_0400", -- load r1 <- retAddr
		X"1104_0401", -- r4 <- r4-1, sp -= 1
		X"1105_0501", -- r5 <- r5-1 recDepth -= 1
		X"4100_0100", -- unspin recursion
		X"0000_0000",

	-- displacement 1
	-- push retAddr, low, high
		X"1001_0018", -- put retAddr, next instrc, in r1
		X"3002_04FE", -- r2 <- low
		X"3003_04FF", -- r3 <- high
		X"3101_0401", -- store M[sp+1] <- retAddr(r1)
		X"3102_0402", -- store M[sp+2] <- low(r2)
		X"3103_0403", -- store M[sp+3] <- high(r3)
		X"1004_0403", -- sp += 3
	-- jump partition
		X"4100_0000", -- jump
		X"0000_0036", -- partition displacement

	-- push retAddr, low, pivot - 1
		X"1001_0023", -- put retAddr, next instrc, in r1
		X"3002_04FE", -- r2 <- low
		X"3003_0400", -- r3 <- pivot
		X"1103_0301", -- r3 = pivot-1
		X"3101_0401", -- store M[sp+1] <- retAddr(r1)
		X"3102_0402", -- store M[sp+2] <- low(r2)
		X"3103_0403", -- store M[sp+3] <- pivot-1(r3)
		X"1004_0404", -- sp += 4
	-- jump QuickSort
		X"1005_0501", -- recDepth += 1
		X"4100_0000", -- jump
		X"0000_0002", -- QuickSort displacement

	-- push retAddr, pivot + 1, high
		X"1001_002E", -- put retAddr, next instrc, in r1
		X"3002_0400", -- r2 <- pivot
		X"3003_04FF", -- r3 <- high
		X"1002_0201", -- r2 = pivot(r2)+1
		X"3101_0401", -- store M[sp+1] <- retAddr(r1)
		X"3102_0402", -- store M[sp+2] <- pivot+1(r2)
		X"3103_0403", -- store M[sp+3] <- high(r3)
		X"1004_0404", -- sp += 4
	-- jump QuickSort
		X"1005_0501", -- recDepth += 1
		X"4100_0000", -- jump
		X"0000_0002", -- QuickSort displacement
	-- if (recCount == 0)
		X"1105_0500", -- r5 <- r5-0
		X"4109_004F", -- recDepth == 0 then jump to the END OF PROGRAM
	-- sp -= 3
		X"1104_0403", -- r4 <- r4-3
	-- return
		X"3001_0400", -- load r1 <- retAddr
		X"1104_0401", -- r4 <- r4-1, sp -= 1
		X"1105_0501", -- recDepth -= 1
		X"4100_0100", -- unspin recursion
		X"0000_0000",


-- Partition //stack: retAddr, low, high
		-- r7 - pivot(not initialized yet)
		-- r8 - left_wall(not initialized yet)
	-- pivot = numbers[high] 	r7 - pivot
		X"3007_0400", -- r7 <- high
		X"0007_0706", -- r7 <- r7+r6 - offset numbers[high]
		X"3007_0700", -- load numbers[high] in r7
	-- left_wall = low - 1 		r8 - left_wall
		X"3008_04FF", -- r8 <- low
		X"1108_0801", -- r8 <- r8-1, low-1
	-- if low >= high: jump over whole loop
		X"3001_04FF", -- load r1 <- low
		X"3002_0400", -- load r2 <- high
		X"0101_0102", -- r1 <- r1-r2, low-high
		X"500A_0002", -- low-high<0 then go loop
		X"4100_0000", -- else jump over loop
		X"0000_0054", -- displacement 3
	-- r9 will be used as loop counter
	-- i = low		 preparing r9 for the loop
		X"3009_04FF", -- r9 <- low
	-- loop displacement
	-- if numbers[i] > pivot
		X"000A_0906", -- r10 <- r9+r6 - offset numbers[i]
		X"300A_0A00", -- r10 <- numbers[i] 
		X"010B_070A", -- r11 <- pivot(r7)-numbers[i]
		X"410A_0000", -- pivot-numbers[i]<0 then continue
		-- continue;
			X"0000_004F", 
	-- left_wall++;
		X"1008_0801", -- r8 <- r8+1
	-- std::swap(numbers[i], numbers[left_wall])
		X"000A_0906", -- r10 <- r9+r6 - offset numbers[i]
		X"300A_0A00", -- r10 <- numbers[i] 
		X"000B_0806", -- r11 <- left_wall+r6, offset numbers[left_wall] 
		X"300C_0B00", -- r12 <- numbers[left_wall]
		X"310A_0B00", -- numbers[left_wall] <- numbers[i](r10)
		X"000B_0906", -- r11 <- r9+r6, offset numbers[i]
		X"310C_0B00", -- numbers[i] <- numbers[left_wall](r12)
	-- i++; (continue)
		X"1009_0901", -- r9 += 1
	-- if i < high: jump loop;
		X"3002_0400", -- load r2 <- high
		X"0102_0902", -- r2 <- i(r9)-high(r2)
		X"410A_0000", -- i-high<0 go looping
		X"0000_0042", -- jump loop
	-- end of loop

  -- displacement 3
	-- left_wall++;
		X"1008_0801", -- r8 <- r8+1
	-- std::swap(numbers[high], numbers[left_wall])
		X"3002_0400", -- load r2 <- high
		X"0002_0602", -- r2 <- high+r6, offset numbers[high] 
		X"3003_0200", -- r3 <- numbers[high]
		X"000B_0806", -- r11 <- left_wall+r6, numbers[left_wall] offset
		X"300C_0B00", -- r12 <- numbers[left_wall]
		X"3103_0B00", -- store numbers[left_wall] <- numbers[high](r3)
		X"310C_0200", -- store numbers[high] <- numbers[left_wall](r12)
	-- Quicksort::pivot = left_wall
		X"3108_04FD", -- store Quicksort::pivot <- left_wall
	-- return;
		X"3002_04FE", -- load r2 <- retAddr
		X"1104_0403", -- sp -= 3;
		X"4100_0200", -- unspin recursion
		X"0000_0000",
-- END OF CODE
	-- array
	X"0000_0010",
	X"0000_0009",
	X"0000_0008",
	X"0000_0007",
	X"0000_0006",
	X"0000_0005",
	X"0000_0004",
	X"0000_0003",
	X"0000_0002",
	-- stack (r4 - stack pointer)
	X"0000_0000", -- low first call
	X"0000_0008", -- high first call
	X"0000_0000", -- pivot first call -- r4 points here at the beginning

		OTHERS => X"0000_0000");
	BEGIN
		--
		-- put d_bus and reply into initial state
		--
		d_bus <= NULL AFTER Tpd;
		ready <= '0' AFTER Tpd;
		--
		-- wait for a command
		--
		WAIT UNTIL (read = '1') OR (write = '1');
		--
		-- dispatch read or write cycle
		--
		address := bits_to_int(a_bus);
		IF address >= low_address AND address <= high_address THEN
			-- address match for this memory
			IF write = '1' THEN
				ready <= '1' AFTER Tpd;
				WAIT UNTIL write = '0'; -- wait until end of write cycle
				mem(address) := d_bus;--'delayed(Tpd); -- sample data from Tpd ago
			ELSE -- read='1'
				d_bus <= mem(address) AFTER Tpd; -- fetch data
				ready <= '1' AFTER Tpd;
				WAIT UNTIL read = '0'; -- hold for read cycle
			END IF;
		END IF;
	END PROCESS;
END behaviour;
