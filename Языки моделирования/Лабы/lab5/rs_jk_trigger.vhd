LIBRARY ieee;
USE ieee.std_logic_1164.all;
ENTITY rs_jk_trigger IS
    PORT (
        c, r, s, j, k : IN STD_LOGIC;
        q, qi : OUT STD_LOGIC
    );
END rs_jk_trigger;

ARCHITECTURE behav OF rs_jk_trigger IS
    SIGNAL qs : STD_LOGIC;
BEGIN
    PROCESS (j, k, c, r, s, qs)
    BEGIN
    IF (c'event and c = '1' ) THEN
        IF (r = '0' and s = '1') THEN
            qs <= '0';
        ELSIF (r = '1' and s = '0') THEN
            qs <= '1';
        ELSIF (r = '0' and s = '0') THEN
            qs <= qs;
        ELSE
            IF (j = '0' and k = '1') THEN
                qs <= '0';
            ELSIF (j = '1' and k = '0') THEN
                qs <= '1';
            ELSIF (j = '0' and k = '0') THEN
                qs <= qs;   
            ELSE    
                qs <= not qs;
            END IF;
        END IF;
    END IF;
    END PROCESS;
    q <= qs;
    qi <= not qs;
END behav;
