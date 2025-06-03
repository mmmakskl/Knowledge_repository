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

