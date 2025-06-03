LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY asynch_dtr IS
  PORT (
    data, clk, reset, preset : IN STD_LOGIC;
    q : OUT STD_LOGIC );
END asynch_dtr;
ARCHITECTURE behav OF asynch_dtr IS
BEGIN
  PROCESS (clk, reset, preset) 
  BEGIN
    IF (reset = '0') THEN
      q <= '0';
    ELSIF(preset = '0') THEN
      q <= '1';
    ELSIF(clk'event and clk = '1') THEN
      q <= data;
    END IF;
  END PROCESS;
END behav;

