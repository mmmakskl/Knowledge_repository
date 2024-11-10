LIBRARY ieee;
USE ieee.std_logic_1164.all;
ENTITY notcomp IS
PORT (
a : IN std_logic;
b : INOUT std_logic
);
END notcomp;
ARCHITECTURE bhur OF notcomp IS
BEGIN
b <= NOT a;
END bhur;

