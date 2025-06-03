library ieee;
use ieee.std_logic_1164.all;

entity DC_str is 
port
(
  x0: in std_logic;
  x1: in std_logic;
  x2: in std_logic;
  x3: in std_logic;
  x4: in std_logic;
  x5: in std_logic;
  ENB: in std_logic;
  q0: out std_logic;
  q1: out std_logic;
  q2: out std_logic;
  q3: out std_logic;
  q4: out std_logic;
  q5: out std_logic;
  q6: out std_logic;
  q7: out std_logic;
  q8: out std_logic;
  q9: out std_logic;
  q10: out std_logic;
  q11: out std_logic;
  q12: out std_logic;
  q13: out std_logic;
  q14: out std_logic;
  q15: out std_logic;
  q16: out std_logic;
  q17: out std_logic;
  q18: out std_logic;
  q19: out std_logic;
  q20: out std_logic;
  q21: out std_logic;
  q22: out std_logic;
  q23: out std_logic;
  q24: out std_logic;
  q25: out std_logic;
  q26: out std_logic;
  q27: out std_logic;
  q28: out std_logic;
  q29: out std_logic;
  q30: out std_logic;
  q31: out std_logic;
  q32: out std_logic;
  q33: out std_logic;
  q34: out std_logic;
  q35: out std_logic;
  q36: out std_logic;
  q37: out std_logic;
  q38: out std_logic;
  q39: out std_logic;
  q40: out std_logic;
  q41: out std_logic;
  q42: out std_logic;
  q43: out std_logic;
  q44: out std_logic;
  q45: out std_logic;
  q46: out std_logic;
  q47: out std_logic;
  q48: out std_logic;
  q49: out std_logic;
  q50: out std_logic;
  q51: out std_logic;
  q52: out std_logic;
  q53: out std_logic;
  q54: out std_logic;
  q55: out std_logic;
  q56: out std_logic;
  q57: out std_logic;
  q58: out std_logic;
  q59: out std_logic;
  q60: out std_logic;
  q61: out std_logic;
  q62: out std_logic;
  q63: out std_logic
);

end DC_str;

architecture behav of DC_str is

component DC_graph
port(
   a0 : in std_logic;
   a1 : in std_logic;
   a2 : in std_logic;
   ENB : in std_logic;
   q0 : out std_logic;
   q1 : out std_logic;
   q2 : out std_logic;
   q3 : out std_logic;
   q4 : out std_logic;
   q5 : out std_logic;
   q6 : out std_logic;
   q7 : out std_logic
	);
end component;
signal enb0: std_logic;
signal enb1: std_logic;
signal enb2: std_logic;
signal enb3: std_logic;
signal enb4: std_logic;
signal enb5: std_logic;
signal enb6: std_logic;
signal enb7: std_logic;
begin
dcEn: DC_graph port map(x3, x4, x5, ENB, enb0, enb1, enb2, enb3, enb4, enb5, enb6, enb7);
dc0: DC_graph port map(x0, x1, x2, enb0, q0, q1, q2, q3, q4, q5, q6, q7);
dc1: DC_graph port map(x0, x1, x2, enb1, q8, q9, q10, q11, q12, q13, q14, q15);
dc2: DC_graph port map(x0, x1, x2, enb2, q16, q17, q18, q19, q20, q21, q22, q23);
dc3: DC_graph port map(x0, x1, x2, enb3, q24, q25, q26, q27, q28, q29, q30, q31);
dc4: DC_graph port map(x0, x1, x2, enb4, q32, q33, q34, q35, q36, q37, q38, q39);
dc5: DC_graph port map(x0, x1, x2, enb5, q40, q41, q42, q43, q44, q45, q46, q47);
dc6: DC_graph port map(x0, x1, x2, enb6, q48, q49, q50, q51, q52, q53, q54, q55);
dc7: DC_graph port map(x0, x1, x2, enb7, q56, q57, q58, q59, q60, q61, q62, q63);


end behav;