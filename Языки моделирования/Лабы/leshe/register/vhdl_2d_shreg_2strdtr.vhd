LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY vhdl_2d_shreg_2strdtr IS
  PORT (
    d, c1, c2, r : IN STD_LOGIC;
    q1, q2, q3, q4 : OUT STD_LOGIC
  );
END vhdl_2d_shreg_2strdtr;

ARCHITECTURE behav OF vhdl_2d_shreg_2strdtr IS
  signal qs1 : std_logic;
  signal q1_o : std_logic;
  signal qs2 : std_logic;
  signal q2_o : std_logic;
  signal qs3 : std_logic;
  signal q3_o : std_logic;
  signal qs4 : std_logic;
  signal q4_o : std_logic;
BEGIN
  PROCESS (d, r, c1)
  BEGIN
    IF r = '0' THEN
      qs1 <= '0';
      qs2 <= '0';
      qs3 <= '0';
      qs4 <= '0';
     ELSIF c1'event and c1 = '1' THEN
       qs4 <= q3_o;
       qs3 <= q2_o;
       qs2 <= q1_o;
       qs1 <= d;
     END IF;
  END PROCESS;

  PROCESS (r, c2)
  BEGIN 
    IF r = '0' THEN
      qs1 <= '0';
      qs2 <= '0';
      qs3 <= '0';
      qs4 <= '0';
      q1_o <= '0';
      q2_o <= '0';
      q3_o <= '0';
      q4_o <= '0';
    ELSIF c2'event and c2 = '1' THEN
      q1_o <= qs1;
      q2_o <= qs2;
      q3_o <= qs3;
      q4_o <= qs4;
    END IF;
  END PROCESS;
  q1 <= q1_o;
  q2 <= q2_o;
  q3 <= q3_o;
  q4 <= q4_o;
END behav;      


