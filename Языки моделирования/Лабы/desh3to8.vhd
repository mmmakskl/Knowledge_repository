LIBRARY ieee;
USE IEEE.std_logic_1164.ALL;

ENTITY dec3to8 IS
    PORT (
        a : IN STD_LOGIC_VECTOR (2 DOWNTO 0);
        en : IN STD_LOGIC;
        q : OUT STD_LOGIC_VECTOR (7 DOWNTO 0));
END dec3to8;

ARCHITECTURE behav OF dec3to8 IS
BEGIN
    PROCESS (a)
    BEGIN
        IF (en = '0') THEN
            q <= "11111111";
        ELSIF (en = '1') THEN
            CASE a IS
                WHEN "000" => q <= "11111110";
                WHEN "001" => q <= "11111101";
                WHEN "010" => q <= "11111011";
                WHEN "011" => q <= "11110111";
                WHEN "100" => q <= "11101111";
                WHEN "101" => q <= "11011111";
                WHEN "110" => q <= "10111111";
                WHEN "111" => q <= "01111111";
                WHEN OTHERS => q <= "11111111";
            END CASE;
        END IF;
    END PROCESS;
END behav;
