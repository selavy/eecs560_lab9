use Heap::MinMax;

my $mm_heap = Heap::MinMax->new();
open( FILE, "test_data.txt" );
@text = <FILE>;

foreach my $line (@text) {
    chop( $line );
    $mm_heap->insert( $line );
}

$mm_heap->print_heap();
my $min = $mm_heap->pop_min();
print "min was: $min\n";
my $max = $mm_heap->pop_max();
print "max was: $max\n";
$mm_heap->print_heap();
$min = $mm_heap->pop_min();
$max = $mm_heap->pop_max();
print "now min is: $min\n";
print "now max is: $max\n";

exit
