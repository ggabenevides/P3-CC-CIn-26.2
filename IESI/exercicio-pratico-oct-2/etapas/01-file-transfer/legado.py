"""Sistema produtor em Python. Execute a partir da raiz do projeto."""
import csv
from pathlib import Path
BASE = Path(__file__).resolve().parent
ORIGEM = BASE.parent.parent / 'dados' / 'produtos.csv'
SAIDA = BASE / 'runtime' / 'saida' / 'produtos.csv'
TEMPORARIO = SAIDA.with_suffix('.tmp') 

def exportar():
    with ORIGEM.open(encoding='utf-8', newline='') as arquivo:
        produtos = list(csv.DictReader(arquivo))
    SAIDA.parent.mkdir(parents=True, exist_ok=True)
    with TEMPORARIO.open('w', encoding='utf-8', newline='') as arquivo:
        writer = csv.DictWriter(arquivo, fieldnames=['sku', 'nome', 'quantidade'])
        writer.writeheader()
        writer.writerows(produtos)
    TEMPORARIO.replace(SAIDA)


if __name__ == '__main__':
    exportar()
    print(f'Snapshot publicado: {SAIDA}')
