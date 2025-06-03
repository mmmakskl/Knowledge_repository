library ieee;
use ieee.std_logic_1164.all;

entity mem_reg_vhdl is
port
(
	x1: in std_logic;
	x2: in std_logic;
	x3: in std_logic;
	x4: in std_logic;
	write: in std_logic;
	reset: in std_logic;
	read: in std_logic;
	d11: out std_logic;
	d22: out std_logic;
	d33: out std_logic;
	d44: out std_logic;
	q1: out std_logic;
	q2: out std_logic;
	q3: out std_logic;
	q4: out std_logic
);
end mem_reg_vhdl;

architecture behaviour of mem_reg_vhdl is
signal d1:std_logic;
signal d2:std_logic;
signal d3:std_logic;
signal d4:std_logic;
begin
	process(write, reset, read)
	begin
		if (write'EVENT and write = '1' and reset = '1') then
			d1 <= x1;
			d2 <= x2;
			d3 <= x3;
			d4 <= x4;
			d11 <= x1;
			d22 <= x2;
			d33 <= x3;
			d44 <= x4;
		end if;
		if (read = '1') then
			q1 <= d1;
			q2 <= d2;
			q3 <= d3;
			q4 <= d4;
		else
			q1 <= '0';
			q2 <= '0';
			q3 <= '0';
			q4 <= '0';
		end if;
	end process;
end behaviour;