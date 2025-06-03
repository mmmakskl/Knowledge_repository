library ieee;
use ieee.std_logic_1164.all;

entity lab_10_6_jk is
	port(
		j, k, c, r, s : IN std_logic;
		q, qi : INOUT std_logic);
end lab_10_6_jk;

architecture behav of lab_10_6_jk is
	signal q_sig : std_logic;
begin
	process(q_sig, c, r, s)begin
		if(r = '0')then
			q_sig <= '0';
		elsif(s = '0')then
			q_sig <= '1';
		elsif(c'event and c = '1')then
			if(j = '1' and k = '1')then
				q_sig <= not q;
			elsif(j = '1')then
				q_sig <= '1';
			elsif(k = '1')then
				q_sig <= '0';
			end if;
		end if;
	end process;
q <= q_sig;
qi <= not q_sig;
end behav;
