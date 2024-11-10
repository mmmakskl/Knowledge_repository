LIBRARY ieee;
USE ieee.std_logic_1164.all;
ENTITY rs_jk_trigger_1 IS
    PORT (
        r, s, j, k : IN STD_LOGIC;
        q, qi : OUT STD_LOGIC
    );
END rs_jk_trigger_1;

ARCHITECTURE behav OF rs_jk_trigger_1 IS
    SIGNAL qs, qsi, qs0 : STD_LOGIC;
BEGIN
    PROCESS (j, k, r, s, qs)
    BEGIN
        IF (r = '0' and s = '0') THEN
            qs <= qs;
        ELSIF (r = '1' and s = '0') THEN
            qs <='1';
        ELSIF (r= '0' and s = '1') THEN
            qs <= '0';
        ELSE
            IF (j'event and j = '1') THEN
                IF (k = '0') THEN 
                    qs <= '1';
                ELSE 
                    qs <= not qs;
                END IF;
            END IF;
        END IF;
    END PROCESS;

    PROCESS (j, k, r, s, qsi)
    BEGIN 
        IF (r= '0' and s = '0') THEN 
            qsi <= qsi;
        ELSIF (r = '1' and s = '0') THEN 
            qsi <= '1';
        ELSIF (r = '0' and s = '1') THEN
            qsi <= '0';
        ELSE 
            IF (k'event and k = '1') THEN 
                IF (j = '0') THEN 
                    qsi <= '0';
                ELSE 
                    qsi <= not qsi;
                END IF;
            END IF;
        END IF;
    END PROCESS;
    q <= qs and qsi;
    qi <= not (qs and qsi);
END behav;

