library ieee;
use ieee.std_logic_1164.all;

entity cip8_3l is
port(
	r: in std_logic_vector(7 downto 0);
	ei: in std_logic;
	a: out std_logic_vector(2 downto 0);
	g: out std_logic;
	eo: out std_logic);
end cip8_3l;

architecture behavior of cip8_3l is
begin
	process(r, ei)
	variable flag: std_logic;
	begin
	if ei = '1' then
		flag := '0';
		a <= "000";
		for i in 7 downto 0 loop
			if r(i) = '1' then
				case i is
					when 0 => a <= "000";
					when 1 => a <= "001";
					when 2 => a <= "010";
					when 3 => a <= "011";
					when 4 => a <= "100";
					when 5 => a <= "101";
					when 6 => a <= "110";
					when 7 => a <= "111";
					when others => a <= "000";
				end case;
				flag := '1';
				exit;
			end if;
		end loop;
		if flag = '0' then
			g <= '0';
			eo <= '1';
		else
			g <= '1';
			eo <= '0';
		end if;
	else
		a <= "000";
		g <= '0';
		eo <= '0';
	end if;
	end process;
end behavior;