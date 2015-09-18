#For NS 82
                echo 00000001 >/proc/irq/53/smp_affinity
                echo 00000002 >/proc/irq/54/smp_affinity
                echo 00000004 >/proc/irq/55/smp_affinity
                echo 00000008 >/proc/irq/56/smp_affinity
		cat /proc/irq/5[3-6]/smp_affinity
