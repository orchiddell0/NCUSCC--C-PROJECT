import pandas as pd
import matplotlib.pyplot as plt

# 读取CSV文件
def read_csv(file_path):
    return pd.read_csv(file_path)

# 设置自定义索引
def set_custom_index(data, new_index):
    data.index = new_index
    return data

# 生成SVG柱状图
def generate_svg_bar_chart(data, column_name, output_file):
    # 设置图形大小
    plt.figure(figsize=(10, 6))
    
    # 创建柱状图
    plt.bar(data.index, data[column_name], color='skyblue')
    
    # 设置标题和标签
    plt.title('')
    plt.xlabel('Index')
    plt.ylabel('Values')
    
    # 保存为SVG格式
    plt.savefig(output_file, format='svg')
    plt.close()

# 主函数
def main():
    # CSV文件路径
    csv_file_path = '/home/orchid/scctest/self_seconds_o.csv'  # 替换为你的CSV文件路径
    # 输出SVG文件路径
    svg_file_path = '/home/orchid/svg/-O0.svg'  # 替换为你想要的SVG文件路径
    
    # 读取数据
    data = read_csv(csv_file_path)
    
    # 假设我们想要绘制名为'Values'的列
    column_name = 'Values'
    
    # 设置自定义索引，例如：['A', 'B', 'C', ...]
    new_index = ['BubbleSort','HeapSort','FibHeapSort'] # 根据需要修改下标内容
    data = set_custom_index(data, new_index)
    
    # 生成SVG图形
    generate_svg_bar_chart(data, column_name, svg_file_path)
    print(f"SVG chart has been saved to {svg_file_path}")

if __name__ == "__main__":
    main()
