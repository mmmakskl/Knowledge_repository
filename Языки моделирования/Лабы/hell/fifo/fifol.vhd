library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity fifol is
port(
	clk:   in std_logic;

	di:    in std_logic_vector(7 downto 0);
	rd:    in std_logic;
	wr:    in std_logic;
	reset: in std_logic;
	
	do:    out std_logic_vector(7 downto 0);
	empty: out std_logic := '1';
	full:  out std_logic);
end fifol;

architecture behavior of fifol is
type stor_t is array(7 downto 0) of std_logic_vector(7 downto 0);
type state_t is (READ, WRITE, REST);
signal stor: stor_t;
signal state: state_t;
signal tail: integer range 0 to 7;
signal head: integer range 0 to 7;
begin
	process(clk, wr, rd, reset, tail, head, di)
	begin
		if reset = '1' then
			head <= 0;
			tail <= 0;
			empty <= '1';
			state <= REST;
		elsif rising_edge(clk) then
			if wr = '1' and state /= WRITE then
				stor(head) <= di;
				empty <= '0';
				if head + 1 = tail then
					full <= '1';
				end if;
				head <= head + 1;
				state <= WRITE;
			elsif rd = '1' and state /= READ then
				do <= stor(tail);
				full <= '0';
				if head = tail + 1 then
					empty <= '1';
				end if;			
				tail <= tail + 1;
				state <= READ;
			elsif rd = '0' and wr = '0' then
				state <= REST;
			end if;
		end if;
	end process;
end behavior;