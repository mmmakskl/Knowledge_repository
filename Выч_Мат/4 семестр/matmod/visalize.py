import pandas as pd
import matplotlib.pyplot as plt

# читаем общий CSV
df = pd.read_csv('bifurcation.csv')

# уникальные значения p4
p4vals = sorted(df['p4'].unique())

for p4 in p4vals:
    sub = df[df['p4'] == p4]
    plt.figure(figsize=(6,4))
    plt.plot(sub['p5'], sub['p2'], marker='>', linestyle='-', markersize=4)
    plt.title(f'Fold Bifurcation: p4={p4}')
    plt.xlabel('p5')
    plt.ylabel('p2')
    plt.grid(True)
    plt.tight_layout()
    plt.savefig(f'bifurcation_p4_{int(p4)}.png')
    plt.close()
    print(f'Сохранён график bifurcation_p4_{int(p4)}.png')