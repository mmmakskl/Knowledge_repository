LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY vhdl_universal_reg IS
  PORT (
    x1, x2, x3, x4, write, read, reset : IN STD_LOGIC;
    q1, q2, q3, q4 : OUT STD_LOGIC
  );

END vhdl_universal_reg;

ARCHITECTURE behavior OF vhdl_universal_reg IS
  SIGNAL i1, i2, i3, i4 : STD_LOGIC := '0';
BEGIN
  PROCESS (write, reset)
  BEGIN
    IF reset = '0' THEN
      i1 <= '0';
      i2 <= '0';
      i3 <= '0';
      i4 <= '0';
    ELSE
      IF (write'event and write = '1') THEN
        i1 <= x1;
        i2 <= x2;
        i3 <= x3;
        i4 <= x4;
      END IF;
    END IF;
  END PROCESS;

  PROCESS (reset, read)
  BEGIN
    IF read = '1'THEN
      q1 <= i1;
      q2 <= i2;
      q3 <= i3;
      q4 <= i4;
    ELSE
      q1 <= '0';
      q2 <= '0';
      q3 <= '0';
      q4 <= '0';
    END IF;
  END PROCESS;
END behavior;
  
