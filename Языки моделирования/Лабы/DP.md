```vhdl
USE work.dp32_types.all, work.alu_32_types.all;
LIBRARY ieee;
USE ieee.std_logic_1164.all;
entity memory is
    generic (Tpd : Time := unit_delay);
    port(
        d_bus : inout bus_bit_32 bus;
        a_bus : in    bit_32;
        read  : in    std_logic;
        write : in    std_logic;
        ready : out   std_logic
    );
end memory;

architecture behaviour of memory is
    constant low_address  : integer := 0;
    constant high_address : integer := 65535;
    type memory_array is array(integer range low_address to high_address) of bit_32;
    variable address : integer := 0;
    variable mem     : memory_array :=
        (
        -- === TEST PROGRAM (identical по примеру 5x5) ===
        X"0700_0000",  -- r0 <- r0 & not r0
        X"2100_0000",  -- store: M[r0+disp32=0] <- r0
        X"0000_005B",  -- disp32 = 91
        X"1005_0501",  -- r5 <- r0 + 129 (base matrix)
        X"0600_0000",  -- logical mask (обнуляем r0)
        X"1000_0500",  -- r0 <- r0 + 80 (base nodes)
        X"5001_0003",--jmp 
			X"0604_0404",
			X"1004_0401", 
			X"5000_0066",--jmp to end prog 
			X"0604_0404",
			X"1100_0001",
			X"2003_0500",
			X"0000_005A",
			X"1000_0301",
			X"2100_0700",
			X"0000_0065",
			X"1101_0704",
			X"5001_0004",
			X"0604_0404",
			X"1004_0401",
			X"0607_0707",
			X"5000_0056",--to end prog 
			X"1007_0701",
			X"1105_0501",
			X"2001_0300",
			X"0000_0056",
			X"1101_0102", 
			X"5009_001A",--branch to while check 
			X"0600_0000",
			X"1000_0002", 
			X"2100_0300", 
			X"0000_0056", 
			X"0602_0202", 
			X"1002_0204", 
			X"1200_0305",--for starts 
			X"0000_0002", 
			X"2001_0000", 
			X"0000_003D", 
			X"1108_0101", 
			X"5001_000B", 
			X"2001_0200", 
			X"0000_0056", 
			X"1109_0102",
			X"5002_0007",
			X"2102_0500",
			X"0000_005B",
			X"1005_0501",
			X"0600_0000",
			X"1000_0001",
			X"2100_0200",
			X"0000_0056",
			X"1102_0201",--for check
			X"1100_0200",
			X"5001_00EC",--jump to place where for starts 
			X"1100_0400",--while check 
			X"5001_003B",--jmp to end prog 
			X"5000_00CA",--jmp to while
			X"0000_0000",
			X"0000_0000",
			X"0000_0000",
			--
			X"0000_0000", X"0000_0001", X"0000_0001", X"0000_0000", X"0000_0000", X"0000_0001", X"0000_0000", X"0000_0000",  -- 0
    X"0000_0000", X"0000_0000", X"0000_0000", X"0000_0001", X"0000_0000", X"0000_0000", X"0000_0000", X"0000_0000",  -- 1
    X"0000_0000", X"0000_0000", X"0000_0000", X"0000_0000", X"0000_0001", X"0000_0001", X"0000_0000", X"0000_0000",  -- 2
    X"0000_0000", X"0000_0000", X"0000_0000", X"0000_0000", X"0000_0001", X"0000_0000", X"0000_0000", X"0000_0000",  -- 3
    X"0000_0000", X"0000_0000", X"0000_0000", X"0000_0000", X"0000_0000", X"0000_0000", X"0000_0000", X"0000_0000",  -- 4
    X"0000_0000", X"0000_0000", X"0000_0000", X"0000_0000", X"0000_0000", X"0000_0000", X"0000_0001", X"0000_0001",  -- 5
    X"0000_0000", X"0000_0000", X"0000_0000", X"0000_0000", X"0000_0000", X"0000_0000", X"0000_0000", X"0000_0000",  -- 6
    X"0000_0000", X"0000_0000", X"0000_0000", X"0000_0000", X"0000_0000", X"0000_0000", X"0000_0000", X"0000_0000",  -- 7
        -- === MATRIX 8×8 (ячейки base..base+7) ===
        -- каждая строка хранится как битовая маска соседей
        X"0000_0026",  -- row 0: 0,1,1,0,0,1,0,0 (0x26)
        X"0000_0008",  -- row 1: 0,0,0,1,0,0,0,0 (0x08)
        X"0000_0030",  -- row 2: 0,0,0,0,1,1,0,0 (0x30)
        X"0000_0010",  -- row 3: 0,0,0,0,1,0,0,0 (0x10)
        X"0000_0000",  -- row 4: 0,0,0,0,0,0,0,0 (0x00)
        X"0000_00C0",  -- row 5: 0,0,0,0,0,1,1,1 (0xC0)
        X"0000_0000",  -- row 6: 0,0,0,0,0,0,0,0 (0x00)
        X"0000_0000",  -- row 7: 0,0,0,0,0,0,0,0 (0x00)

        -- === NODES (метки посещённости) 8 элементов ===
        X"0000_0000", X"0000_0000", X"0000_0000", X"0000_0000",
        X"0000_0000", X"0000_0000", X"0000_0000", X"0000_0000",

        -- === STACK (8 элементов) ===
        X"0000_0000", X"0000_0000", X"0000_0000", X"0000_0000",
        X"0000_0000", X"0000_0000", X"0000_0000", X"0000_0000",

        -- === RESULT (порядок обхода) 8 элементов ===
        X"0000_0000", X"0000_0000", X"0000_0000", X"0000_0000",
        X"0000_0000", X"0000_0000", X"0000_0000", X"0000_0000",

        OTHERS => X"0000_0000"
        );
begin
    process
    begin
        d_bus <= null after Tpd;
        ready <= '0' after Tpd;
        wait until (read = '1') or (write = '1');
        address := bits_to_int(a_bus);
        if (address >= low_address) and (address <= high_address) then
            if write = '1' then
                ready <= '1' after Tpd;
                wait until write = '0';
                mem(address) := d_bus'delayed(Tpd);
            else
                d_bus <= mem(address) after Tpd;
                ready <= '1' after Tpd;
                wait until read = '0';
            end if;
        end if;
    end process;
end behaviour;

```

```VHDL
USE work.dp32_types.all,work.alu_32_types.all;
LIBRARY ieee;
USE ieee.std_logic_1164.all;
entity memory is
	generic (Tpd	:Time:= unit_delay);
	port (	d_bus	:inout bus_bit_32 bus;
			a_bus	:in  bit_32;
			read	:in  std_logic;
			write	:in  std_logic;
			ready	:out std_logic);
end  memory;
ARCHITECTURE behaviour OF memory IS
begin
	process
		constant  low_address :integer :=0;
		constant high_address :integer :=65535;
		type memory_array is 
			array(integer range low_address to high_address)of bit_32;
		variable address : integer:=0;
		variable mem :memory_array:=
			(X"0700_0000",
			X"2100_0000",
			X"0000_005B",
			X"1005_0501",
			X"0600_0000", 
			X"1000_0500",--while starts 
			X"5001_0003",--jmp 
			X"0604_0404",
			X"1004_0401", 
			X"5000_0066",--jmp to end prog 
			X"0604_0404",
			X"1100_0001",
			X"2003_0500",
			X"0000_005A",
			X"1000_0301",
			X"2100_0700",
			X"0000_0065",
			X"1101_0704",
			X"5001_0004",
			X"0604_0404",
			X"1004_0401",
			X"0607_0707",
			X"5000_0056",--to end prog 
			X"1007_0701",
			X"1105_0501",
			X"2001_0300",
			X"0000_0056",
			X"1101_0102", 
			X"5009_001A",--branch to while check 
			X"0600_0000",
			X"1000_0002", 
			X"2100_0300", 
			X"0000_0056", 
			X"0602_0202", 
			X"1002_0204", 
			X"1200_0305",--for starts 
			X"0000_0002", 
			X"2001_0000", 
			X"0000_003D", 
			X"1108_0101", 
			X"5001_000B", 
			X"2001_0200", 
			X"0000_0056", 
			X"1109_0102",
			X"5002_0007",
			X"2102_0500",
			X"0000_005B",
			X"1005_0501",
			X"0600_0000",
			X"1000_0001",
			X"2100_0200",
			X"0000_0056",
			X"1102_0201",--for check
			X"1100_0200",
			X"5001_00EC",--jump to place where for starts 
			X"1100_0400",--while check 
			X"5001_003B",--jmp to end prog 
			X"5000_00CA",--jmp to while
			X"0000_0000",
			X"0000_0000",
			X"0000_0000",
			X"0000_0000",--matrix of graph 0 row 
			X"0000_0001",
			X"0000_0001",
			X"0000_0000",
			X"0000_0000",
			X"0000_0000",--1 row 
			X"0000_0000",
			X"0000_0000",
			X"0000_0001",
			X"0000_0000",
			X"0000_0000",--2 row 
			X"0000_0000",
			X"0000_0000",
			X"0000_0001",
			X"0000_0001",
			X"0000_0000",--3 row 
			X"0000_0000",
			X"0000_0000",
			X"0000_0000",
			X"0000_0000",
			X"0000_0000",--4 row 
			X"0000_0000",
			X"0000_0000",
			X"0000_0000", 
			X"0000_0000",--end of matrix 
			X"0000_0000",--nodes array 
			X"0000_0000",
			X"0000_0000",
			X"0000_0000",
			X"0000_0000",--end of nodes array
			X"0000_0000",--stack 
			X"0000_0000", 
			X"0000_0000", 
			X"0000_0000", 
			X"0000_0000", 
			X"0000_0000", 
			X"0000_0000", 
			X"0000_0000", 
			X"0000_0000", 
			X"0000_0000",--end of stack 
			X"0000_0000",--results 
			X"0000_0000", 
			X"0000_0000", 
			X"0000_0000", 
			X"0000_0000", 
			X"0000_0000",--end of results others =>
			X"0000_0000",
			others =>X"0000_0000");
		begin
		--
		-- put d_bus and reply into initial state
		--
		d_bus <=null after Tpd;
		ready <='0' after Tpd;
		--
		-- wait for a command
		--
		wait until (read='1')or(write='1');
		--
		-- dispatch read or write cycle
		--
		address := bits_to_int(a_bus);
		if address >=low_address and address <=high_address then
			-- address match for this memory
			if write ='1' then
				ready<='1' after Tpd;
				wait until write='0'; -- wait until end of write cycle
				mem(address):=d_bus'delayed(Tpd); -- sample data from Tpd ago
			else  -- read='1'
				d_bus <= mem(address) after Tpd;	-- fetch data
				ready <='1' after Tpd;
				wait until read='0'; -- hold for read cycle
			end if;
		end if;
	end process;		
end behaviour;						


```


```VHDL
USE work.dp32_types.all,work.alu_32_types.all;
LIBRARY ieee;
USE ieee.std_logic_1164.all;
entity memory is
    generic (Tpd    :Time:= unit_delay);
    port (    d_bus    :inout bus_bit_32 bus;
            a_bus    :in  bit_32;
            read    :in  std_logic;
            write    :in  std_logic;
            ready    :out std_logic);
end  memory;
ARCHITECTURE behaviour OF memory IS
begin
    process
        constant  low_address :integer :=0;
        constant high_address :integer :=65535;
        type memory_array is 
            array(integer range low_address to high_address)of bit_32;
        variable address : integer:=0;
        variable mem :memory_array:=
            (
            -- initialize registers and pointers
            X"0700_0000", -- r0 <- r0 & not r0  ; clear r0
            X"1001_0000", -- r1 <- r0 + 0      ; top = 0
            X"1002_0008", -- r2 <- r0 + 8      ; N = 8
            X"1003_0000", -- r3 <- r0 + 0      ; idx = 0
            -- clear visited array (addr 200..207)
            -- loop: for i in 0..7: store 0
            X"1104_0001", -- r4 <- r0 - 1     ; r4 = -1 (will be incremented)
            -- while: r4 < 7
            X"04050402", -- r5 <- r4 & r2    ; test r4 - 7
            X"50010002", -- if Z=1 skip clear
            X"1004_0001", -- r4 <- r0 + 1
            X"210400C8", -- store r4 -> M[r0 + 200 + r4]
            X"5000_00F5", -- jump back
            -- push start node 0
            X"1005_0000", -- r5 <- r0 + 0
            X"2105_00C0", -- store r5 -> stack[0] (addr 192)
            X"1001_0001", -- r1 <- r0 + 1      ; top = 1
            -- DFS loop
            -- while top > 0
            X"1106_0100", -- r6 <- r1 - r0    ; test top
            X"04060600", -- r6 <- r6 & r6    ; if zero
            X"50020004", -- if Z=1 exit loop
            -- pop: top := top - 1; r1
            X"1101_0101", -- r1 <- r1 - 1
            X"2007_00C0", -- r7 <- M[r0 + 192 + r1] ; pop node
            -- mark visited
            X"1008_0001", -- r8 <- r0 + 1
            X"2108_00C8", -- store r8 -> visited[r7]
            -- for k in 0..7
            X"1009_0000", -- r9 <- r0 + 0 ; k
            -- for_loop_start:
            X"040A0402", -- r10 <- r4 & r2 ; compare k and N
            X"50010003", -- if Z=1 end for
            -- load adjacency[r7]
            X"200B_00BE", -- r11 <- M[r0 + 190 + r7] ; base addr 190
            X"200C_00E6", -- r12 <- M[r0 + 230 + r9] ; mask[k]
            X"040D_0B0C", -- r13 <- r11 & r12
            X"50010005", -- if Z=1 skip push
            -- push k
            X"2109_00C0", -- store r9 -> stack[r1]
            X"1001_0001", -- r1 <- r0 + 1 ; top++
            X"5000_0002", -- jump for_loop_continue
            -- skip push
            -- for_loop_continue:
            X"1009_0101", -- r9 <- r9 + 1 ; k++
            X"5000_FFEE", -- jump to for_loop_start
            -- end while
            -- infinite halt
            X"5000_00FF",
            -- === DATA SECTION ===
            -- stack area (192..199)
            X"00000000", X"00000000", X"00000000", X"00000000",
            X"00000000", X"00000000", X"00000000", X"00000000",
            -- visited area (200..207)
            X"00000000", X"00000000", X"00000000", X"00000000",
            X"00000000", X"00000000", X"00000000", X"00000000",
            -- adjacency base (8 rows * one word bitmask)
            X"00000026", -- row 0: 0b00100110
            X"00000009", -- row 1: 0b00001001
            X"00000031", -- row 2: 0b00110001
            X"00000012", -- row 3: 0b00010010
            X"0000000C", -- row 4: 0b00001100
            X"000000C5", -- row 5: 0b11000101
            X"00000020", -- row 6: 0b00100000
            X"00000020", -- row 7: 0b00100000
            -- mask table (8 entries)
            X"00000001", X"00000002", X"00000004", X"00000008",
            X"00000010", X"00000020", X"00000040", X"00000080",
            others => X"0000_0000");
        begin
        d_bus <=null after Tpd;
        ready <='0' after Tpd;
        wait until (read='1')or(write='1');
        address := bits_to_int(a_bus);
        if address >=low_address and address <=high_address then
            if write ='1' then
                ready<='1' after Tpd;
                wait until write='0';
                mem(address):=d_bus'delayed(Tpd);
            else
                d_bus <= mem(address) after Tpd;
                ready <='1' after Tpd;
                wait until read='0';
            end if;
        end if;
    end process;        
end behaviour;

```