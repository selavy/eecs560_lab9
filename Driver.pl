use Heap::MinMax;

my $mm_heap = Heap::MinMax->new();
open( FILE, "test_data.txt" );
@text = <FILE>;

$counter = 0;
foreach my $line (@text) {
    chop( $line );
    $mm_heap->insert( $line );
    $counter++;
}

$mm_heap->print();
{
    use integer;
    $upperLimit = $counter / 8;
}

for( $i = 0; $i < $upperLimit; ++$i ) {
    print "min: " . $mm_heap->min() . "\n";
    print "max: " . $mm_heap->max() . "\n";
    $mm_heap->pop_min();
    $mm_heap->pop_max();
}

$mm_heap->insert( 5 );
$mm_heap->insert( 100 );
$mm_heap->insert( -200 );
$mm_heap->insert( -500 );

for( $i = 0; $i < $upperLimit; ++$i ) {
    print "min: " . $mm_heap->min() . "\n";
    print "max: " . $mm_heap->max() . "\n";
    $mm_heap->pop_min();
    $mm_heap->pop_max();
}


exit
