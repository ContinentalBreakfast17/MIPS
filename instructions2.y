%%
instruction 			: inst_rd_rs reg reg
						{

						}
						| inst_rd_rs_rt reg reg reg
						{

						}
						| inst_rt_rs_im reg reg im
						{

						}
						| inst_rs_rt reg reg
						{

						}
						| inst_rd_rt_sh rd rt sh
						{

						}
						| inst_rt_im rt im 
						{

						}
						| inst_rt_l_im rt l_im
						{

						}
						| inst_tg TG
						{

						}
						| inst_cc_tg cc tg
						{

						}
						| inst_rs_tg rs TG
						{

						}
						| inst_rs_rt_tg rs rt TG
						{

						}
						| inst_rs_rd rs rd
						{

						}
						| 