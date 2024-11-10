-- 7. Structural highest one 8:8

LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY high8to8 IS
    PORT (
        input : IN STD_LOGIC_VECTOR(7 DOWNTO 0);
        enable : IN STD_LOGIC;
        output : OUT STD_LOGIC_VECTOR(7 DOWNTO 0));
END high8to8;

ARCHITECTURE behav OF high8to8 IS
    COMPONENT enc8to3
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
    END COMPONENT;

    COMPONENT dec3to8
        PORT (
            a : IN STD_LOGIC_VECTOR (2 DOWNTO 0);
            en : IN STD_LOGIC;
            q : OUT STD_LOGIC_VECTOR (7 DOWNTO 0));
    END COMPONENT;

    SIGNAL output_signal : STD_LOGIC_VECTOR(2 DOWNTO 0);
    SIGNAL G_signal : STD_LOGIC;

BEGIN
    -- Encoders 8->3:
    u1 : enc8to3 PORT MAP(input, enable, output_signal, OPEN, G_signal);
    u2 : dec3to8 PORT MAP(output_signal, G_signal, output);
END behav;

CONFIGURATION con OF high8to8 IS
    FOR behav
        FOR u1 : enc8to3
            USE ENTITY work.enc8to3(behav);
        END FOR;

        FOR u2 : dec3to8
            USE ENTITY work.dec3to8(behav);
        END FOR;
    END FOR;
END con;