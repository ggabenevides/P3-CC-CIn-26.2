import { readFile, mkdir, writeFile, rename } from 'node:fs/promises';
import { lerCsv } from '../../apoio/csv.js';
import { pendente } from '../../apoio/exercicio.js';
const recebido = new URL('./runtime/entrada/produtos.csv', import.meta.url);
const destino = new URL('./runtime/local/produtos.csv', import.meta.url);
try {
  const texto = await readFile(recebido, 'utf8');
  const produtos = lerCsv(texto);
  // TODO [FT-2] O que seria necessário inserir aqui?
  // Valide SKU único e não vazio, nome não vazio e quantidade inteira >= 0.
  // Rejeite o arquivo inteiro se uma linha for inválida; preserve o snapshot anterior.

  function validarProduto(produto) {
    if (!produto.sku || produto.sku.trim() === '') {
      throw new Error(`SKU inválido: "${produto.sku}"`);
    }
    if (!produto.nome || produto.nome.trim() === '') {
      throw new Error(`Nome inválido para SKU "${produto.sku}"`);
    }
    const stringQuantidade = String(produto.quantidade ?? '').trim();
    const quantidade = Number(stringQuantidade);
    if (!Number.isInteger(quantidade) || Number.isNaN(quantidade) || quantidade < 0) {  
      throw new Error(`Quantidade inválida para SKU "${produto.sku}": "${produto.quantidade}"`);
    }
  }

  const skusVistos = new Set();
  for (const produto of produtos) {
    validarProduto(produto);
    if (skusVistos.has(produto.sku)) {
      throw new Error(`SKU duplicado encontrado: "${produto.sku}"`);
    }
    skusVistos.add(produto.sku);
  }

  await mkdir(new URL('./runtime/local/', import.meta.url), { recursive: true });
  const temporario = new URL('./runtime/local/produtos.tmp', import.meta.url);
  await writeFile(temporario, texto, 'utf8');
  await rename(temporario, destino);
  console.log(`Importados ${produtos.length} produtos. Snapshot substituído.`);
} catch (erro) { console.error(erro.message); process.exitCode = 1; }
