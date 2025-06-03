 LIBRARY ieee;USE ieee.std_logic_1164.all;


ENTITY jkrs_l IS

PORT
(
s : IN STD_LOGIC;
j : IN STD_LOGIC;
k : IN STD_LOGIC;
r : IN STD_LOGIC;
q : INOUT STD_LOGIC;
qi : INOUT STD_LOGIC
);

END jkrs_l;

ARCHITECTURE behav OF jkrs_l IS

  SIGNAL  qs, qis : STD_LOGIC;

BEGIN

process (j, k, r, s, qs)
begin
  
if (r = '0' and s = '0') then
  qs <= qs;
elsif (r = '1' and s = '0') then
  qs <= '1';
elsif (r = '0' and s = '1') then
  qs <= '0';
else
  if (j'event and j = '1') then
    if (k = '0') then
      qs <= '1';
    else
      qs <= not qs;
    end if;
  end if;
end if;
end process;
  
process (j, k, r, s, qis)
begin
  
if (r = '0' and s = '0') then
  qis <= qis;
elsif (r = '1' and s = '0') then
  qis <= '0';
elsif (r = '0' and s = '1') then
  qis <= '1';
else
  if (k'event and k = '1') then
    if (j = '0') then
      qis <= '0';
    else
      qis <= not qis;
    end if;
  end if;
end if;
end process;


process (j, k, r, s, q, qis) begin
if (s = '0' and r ='1' and k = '0' and j = '0') then
qi <= '0' ;
q <= not qi;
elsif (s = '1' and r ='0' and k = '0' and j = '0') then
q <= '0' ;
qi <= not q;
else
q <= qs and qis;
qi <= not (qs and qis);
end if;
end process;

END behav;
