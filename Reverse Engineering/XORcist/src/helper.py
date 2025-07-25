part1 = b'NevComp{ezzz_lah_ya_baru'
part2 = b'_pemanasan_cuman_basic_x0r_doang}'

enc1 = [hex(b ^ 0x13) for b in part1]
enc2 = [hex(b ^ 0x37) for b in part2]

print("Part 1:")
print(", ".join(enc1))
print("\nPart 2:")
print(", ".join(enc2))
