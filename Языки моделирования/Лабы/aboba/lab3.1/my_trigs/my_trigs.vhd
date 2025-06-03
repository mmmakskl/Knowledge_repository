library ieee;
use ieee.std_logic_1164.all;

package my_trigs is
component notand is
port(a,b:in std_logic; c:inout std_logic);

end component notand;

end package my_trigs;
