#/bin/bash

mkdir -p output_visual/ tmp/

meshlabserver -i output_visual/base_link.stl -o tmp/0.stl -s ../meshlab_00_simplify_15percent.mlx
cp -f tmp/0.stl output_visual/base_link.stl

meshlabserver -i output_visual/link_1_s.stl -o tmp/0.stl -s ../meshlab_00_simplify_15percent.mlx
cp -f tmp/0.stl output_visual/link_1_s.stl

meshlabserver -i output_visual/link_2_l.stl -o tmp/0.stl -s ../meshlab_00_simplify_15percent.mlx
cp -f tmp/0.stl output_visual/link_2_l.stl

meshlabserver -i output_visual/link_3_u.stl -o tmp/0.stl -s ../meshlab_00_simplify_15percent.mlx
cp -f tmp/0.stl output_visual/link_3_u.stl

meshlabserver -i output_visual/link_4_r.stl -o tmp/0.stl -s ../meshlab_00_simplify_15percent.mlx
cp -f tmp/0.stl output_visual/link_4_r.stl

meshlabserver -i output_visual/link_5_b.stl -o tmp/0.stl -s ../meshlab_00_simplify_15percent.mlx
cp -f tmp/0.stl output_visual/link_5_b.stl

meshlabserver -i output_visual/link_6_t.stl -o tmp/0.stl -s ../meshlab_00_simplify_15percent.mlx
cp -f tmp/0.stl output_visual/link_6_t.stl
