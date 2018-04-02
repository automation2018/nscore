import argparse
import sys

#Filter from file given as second argument w.r.t given filters as first argument.
def filterdata(filterlist, target_file):
    buf=[]
    with open(target_file) as reader_file:
        for line in reader_file:
            if filterlist[0] in line:
                buf.append(line)
#    print len(buf)
    if len(buf) == 0:
        print "Nothing found with applied filters"
        sys.exit(1)
    while len(buf) > 1:
        for filterval in filterlist[1:]:
            for filtered in buf[:]:
                if filterval not in filtered:
                    buf.remove(filtered)
#    print buf[0]
    return float(buf[0].split('|')[5])


#Calculates the difference between baseline and current values.
def get_diff_checked(val_for_baseline, val_for_current):
    if val_for_baseline != 0.000 and val_for_current != 0.000:
        diff=((val_for_baseline-val_for_current)/val_for_baseline)*100
#        print "Opting for percentage difference"
#        print diff 
    else:
#        print "Opting for numeric difference"
        diff = val_for_baseline-val_for_current
#        print diff 
#    if diff > 5 or diff < -5:
    return diff
#        print "going to return 1"
#        return 1
#    else:
#        print "going to return 0"
#        return 0


if __name__ == '__main__':
    parser=argparse.ArgumentParser()
    parser.add_argument('baseline_file', help='Path of baseline summary_gdf.data file')
    parser.add_argument('current_file', help='Path of current summary_gdf.data file')
    parser.add_argument('filterlist1', help='Comma seperated list of filters to be applied on baseline testrun')
    parser.add_argument('filterlist2', help='Comma seperated list of filters to be applied on current testrun')

    args = parser.parse_args()
    filterlist=args.filterlist1
    filter1=filterlist.split(';')
    
    filtersecond=args.filterlist2
    filter2=filtersecond.split(';')
    # In case of simulated protocol, both values under comparison are taken from current test run
    if any("Simulated" in s for s in filter2):
        val_for_baseline=float('%.3f' % filterdata(filter1, args.current_file))
    else:
        val_for_baseline=float('%.3f' % filterdata(filter1, args.baseline_file))
    val_for_current=float('%.3f' % filterdata(filter2, args.current_file))
    diff=get_diff_checked(val_for_baseline, val_for_current)
    print "{},{},{}".format(val_for_baseline, val_for_current, diff)
#    rc=get_diff_checked(val_for_baseline, val_for_current)
#    sys.exit(r)
