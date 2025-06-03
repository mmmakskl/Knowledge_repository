library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity lifol is
port(
	clk:   in std_logic;

	di:    in std_logic_vector(7 downto 0);
	rd:    in std_logic;
	wr:    in std_logic;
	reset: in std_logic;
	
	do:    out std_logic_vector(7 downto 0);
	empty: out std_logic := '1';
	full:  out std_logic);
end lifol;

architecture behavior of lifol is
type stor_t is array(7 downto 0) of std_logic_vector(7 downto 0);
type state_t is (READ, WRITE, REST);
signal stor: stor_t;
signal state: state_t;
signal curr: integer range 0 to 7;
begin
	process(clk, wr, rd, reset, curr, di)
	begin
		if reset = '1' then
			curr <= 0;
			empty <= '1';
			state <= REST;
		elsif rising_edge(clk) then
			if wr = '1' and state /= WRITE then
				stor(curr) <= di;
				curr <= curr + 1;
				state <= WRITE;
				empty <= '0';
				if curr = 7 then
					full <= '1';
				end if;
			elsif rd = '1' and state /= READ then
				do <= stor(curr - 1);
				curr <= curr - 1;
				state <= READ;
				if curr = 1 then
					empty <= '1';
				end if;
				full <= '0';
			elsif rd = '0' and wr = '0' then
				state <= REST;
			end if;
		end if;
	end process;
end behavior;