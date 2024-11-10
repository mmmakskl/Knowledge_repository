-- 3. Behavior priority encoder 8->3.

LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY enc8to3 IS
    PORT (
        input : IN STD_LOGIC_VECTOR (7 DOWNTO 0);
        enable : IN STD_LOGIC;
        output : OUT STD_LOGIC_VECTOR (2 DOWNTO 0);
        -- Would be 1 if and only if `input` is all zeroes but `enable` is 1.
        EO : INOUT STD_LOGIC;
        -- Wouble be 0 if and only if either:
        --   1. `input` is all zeroes but `enable` is 1;
        --   2. `input` is any combination but `enable` is 0.
        G : OUT STD_LOGIC);
END enc8to3;

ARCHITECTURE behav OF enc8to3 IS
BEGIN
    PROCESS (input)
    BEGIN
        IF (enable = '0') THEN
            output <= "000";
            G <= '0'; -- `input` is any combination but `enable` is 0.
            EO <= '0';
        ELSE
            IF (input = "00000000") THEN
                EO <= '1'; -- 1 if and only if `input` is all zeroes but `enable` is 1.
            ELSE
                EO <= '0';
            END IF;

            IF (input(7) = '1') THEN
                output <= "111";
            ELSIF (input(6) = '1') THEN
                output <= "110";
            ELSIF (input(5) = '1') THEN
                output <= "101";
            ELSIF (input(4) = '1') THEN
                output <= "100";
            ELSIF (input(3) = '1') THEN
                output <= "011";
            ELSIF (input(2) = '1') THEN
                output <= "010";
            ELSIF (input(1) = '1') THEN
                output <= "001";
            ELSE
                output <= "000";
            END IF;

            G <= NOT(EO);
        END IF;
    END PROCESS;
END behav;