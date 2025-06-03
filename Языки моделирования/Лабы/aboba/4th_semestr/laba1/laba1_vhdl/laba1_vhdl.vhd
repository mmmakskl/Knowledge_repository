LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

ENTITY laba1_vhdl IS
  PORT (
    data : IN STD_LOGIC_VECTOR (7 DOWNTO 0);
    kks : IN STD_LOGIC_VECTOR (7 DOWNTO 0);
    clock : IN STD_LOGIC;
    query : IN STD_LOGIC;
    q : OUT STD_LOGIC_VECTOR (7 DOWNTO 0);
    synchro : OUT STD_LOGIC;
    get : OUT STD_LOGIC
  );
END laba1_vhdl;
ARCHITECTURE behav OF laba1_vhdl IS
  TYPE t_Row_Col IS ARRAY (0 TO 7) OF STD_LOGIC_VECTOR (7 DOWNTO 0);
  SHARED VARIABLE getVal : BOOLEAN;
  SHARED VARIABLE kksFound : BOOLEAN;
  SHARED VARIABLE gde_detonator : BOOLEAN;
  SIGNAL dffs : t_Row_Col;
  SIGNAL counter : INTEGER RANGE 0 TO 8;
BEGIN
  PROCESS (clock, kks, counter, query)
    VARIABLE tmp : STD_LOGIC_VECTOR (7 DOWNTO 0);
  BEGIN
    IF query = '1' THEN
      gde_detonator := true;
    END IF;
    IF getVal = true THEN
      gde_detonator := false;
    END IF;
    IF (kks = dffs(7)) THEN
      synchro <= '1';
      kksFound := true;
    ELSE
      synchro <= '0';
      kksFound := false;
    END IF;
    IF rising_edge(clock) THEN
      IF ((counter = 8) or (kksFound)) THEN
        IF gde_detonator THEN
          get <= '1';
          getVal := true;
        ELSE
          get <= '0';
          getVal := false;
        END IF;
      END IF;
      IF ((kksFound) OR (counter = 8)) THEN
        counter <= 0;
      ELSE
        counter <= counter + 1;
      END IF;
      tmp := dffs(7);
      FOR k IN 7 DOWNTO 1 LOOP
        dffs(k) <= dffs(k - 1);
      END LOOP;
      IF (getVal) THEN
        dffs(0) <= data;
      ELSE
        dffs(0) <= tmp;
      END IF;
    END IF;
  END PROCESS;
  q <= dffs(7);
END behav;