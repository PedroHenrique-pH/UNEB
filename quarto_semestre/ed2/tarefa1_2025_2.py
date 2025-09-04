import pandas as pd
import time

dados = pd.read_csv('archive/ai_assistant_usage_student_life.csv')

tempo_inicio_invertido = time.time()
print(dados.sort_values('SessionID', ascending=False))
tempo_fim_invertido = time.time()

tempo_inicio = time.time()
print(dados.sort_values('SessionID', ascending=True))
tempo_fim = time.time()

print(f"Tempo de execução da primeira função, ordenada: {tempo_fim - tempo_inicio}")
print(f"Tempo da segunda função, ordenada invertida: {tempo_fim_invertido - tempo_inicio_invertido}")