part1 = b'NevComp{just_b4sic_byte'
part2 = b'c0d3_python_4n4lysIs}'

enc1 = [hex(b << 1) for b in part1]
enc2 = [hex(b << 3) for b in part2]

print("Part 1:")
print(", ".join(enc1))
print("\nPart 2:")
print(", ".join(enc2))