LIBRARY ieee;
USE ieee.std_logic_1164.all;
ENTITY FbitReg IS
 PORT
 (clk : IN STD_LOGIC ;
 data : IN STD_LOGIC ;
 reset : IN STD_LOGIC ;
 q : OUT STD_LOGIC
 );
END FbitReg;
ARCHITECTURE behav OF FbitReg IS
 SIGNAL rs: STD_LOGIC_VECTOR (3 downto 0) ;
BEGIN
process (clk, reset) begin
 if (reset = '0') then
 rs <= "0000";
176
 elsif (clk'event and clk = '1') then
 rs <= data & rs(3 downto 1);
 end if;
end process;
q <= rs(0);
END behav;