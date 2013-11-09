import static java.util.AbstractMap.SimpleImmutableEntry;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;
import java.text.DecimalFormat;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        DecimalFormat formatter = new DecimalFormat("0.00");
        int n = scanner.nextInt();

        while (n-- > 0) {
            int m = scanner.nextInt();

            List<SimpleImmutableEntry<Double, Double>> vertices = new ArrayList<SimpleImmutableEntry<Double, Double>>();

            for (int i = 0; i < m; ++i)
                vertices.add(new SimpleImmutableEntry<Double, Double>(scanner.nextDouble(), scanner.nextDouble()));

            List<Partition<Integer>> partitions = new ArrayList<Partition<Integer>>(m);

            for (int i = 0; i < m; ++i)
                partitions.add(Partition.singleton(i));

            Set<Edge<Partition<Integer>, Double>> edges = new TreeSet<Edge<Partition<Integer>, Double>>();

            for (int i = 0; i < vertices.size(); ++i) {
                SimpleImmutableEntry<Double, Double> from = vertices.get(i);

                for (int j = 0; j < vertices.size(); ++j) {
                    if (i == j) continue;

                    SimpleImmutableEntry<Double, Double> to = vertices.get(j);

                    double weight = Math.sqrt(Math.pow(from.getKey() - to.getKey(), 2.0) + Math.pow(from.getValue() - to.getValue(), 2.0));
                    edges.add(new Edge<Partition<Integer>, Double>(partitions.get(i), partitions.get(j), weight));
                }
            }

            PriorityQueue<Edge<Partition<Integer>, Double>> candidates = new PriorityQueue<Edge<Partition<Integer>, Double>>(edges);

            edges = new HashSet<Edge<Partition<Integer>, Double>>();

            while (m > 1) {
                Edge<Partition<Integer>, Double> edge = candidates.poll();

                if (!Partition.areMerged(edge.getFrom(), edge.getTo())) {
                    edge.getFrom().merge(edge.getTo());
                    edges.add(edge);
                    --m;
                }
            }

            double minWeight = 0.0;

            for (Edge<Partition<Integer>, Double> edge : edges)
                minWeight += edge.getWeight();

            System.out.println(formatter.format(minWeight));

            if (n > 0)
                System.out.println();
        }
    }
}

class Edge<E extends Comparable<? super E>, T extends Comparable<? super T>> implements Comparable<Edge<E, T>> {
    private final E from;
    private final E to;
    private final T weight;

    public Edge(final E from, final E to, final T weight) {
        this.from = from;
        this.to = to;
        this.weight = weight;
    }

    public E getFrom() {
        return from;
    }

    public E getTo() {
        return to;
    }

    public T getWeight() {
        return weight;
    }

    @Override
    public int compareTo(Edge<E, T> edge) {
        int result = weight.compareTo(edge.weight);

        if (result != 0) return result;

        result = from.compareTo(edge.from);

        if (result != 0) return result;

        return to.compareTo(edge.to);
    }

    @Override
    public boolean equals(Object other) {
        if (other == null) return false;
        if (getClass() != other.getClass()) return false;

        Edge<?, ?> that = (Edge<?, ?>) other;

        return from.equals(that.getFrom()) && to.equals(that.getTo()) && weight.equals(that.getWeight());
    }

    @Override
    public int hashCode() {
        int result = 41 + from.hashCode();
        result = 41 * result + to.hashCode();
        result = 41 * result + weight.hashCode();

        return result;
    }
}

/**
 * Code is from http://flexigraph.googlecode.com/svn/trunk/src/gr/forth/ics/util/Partition.java
 * with some modifications.
 */

/**
 * Implementation of disjoint-set data structure, providing merge(merge)/find operations, in
 * order to be able to track whether two elements belong in the same set or not, and
 * to efficiently merge two sets.
 *
 * <p>The set that contains a particular element {@code e} (of type {@code Partition}
 * is accessed by {@code e.find()}.
 * Note that the returned set is merely an element itself, which is used as a representative of
 * the set. So, if two elements have the same representative, they belong to the same set.
 * Otherwise, they belong to different sets. Note that the elements of a particular set cannot be
 * queried directly. Thus, perhaps confusingly, a {@code Partition} represents both a single
 * element <em>and</em> potentially a set of elements, in the particular partition happens
 * to be chosen as the representative of its set.
 *
 * <p>A <em>partition</em> is initially {@link #singleton(Object) created as a singleton}.
 * It accepts an arbitrary (user-defined) value (of type {@code <E>})
 * that is permanently associated with the created partition, and can be accessed by {@link #value()}.
 * A created partition is independent from any other created partition. This means that the return value
 * of {@link #find()} is unique, and method {@link #areMerged(Partition, Partition)}
 * always returns false when given such a partition as an argument.
 *
 * <p>A partition {@code p1} may be <em>merged</em> with another partition {@code p2} by
 * {@code p1.merge(p2);} (or, equivalently, {@code p2.merge(p1);}). From that point on,
 * this invariant is created: {@code p1.find() == p2.find()} which remains true regardless of
 * other future merge operations. Similarly, {@code areMerged(p1, p2)} will always return {@code true}.
 *
 * <p>All methods throw {@code NullPointerException} if given {@code null} arguments.
 *
 * @param <E> the type of the arbitrary (user-defined) element associated with a partition
 * @author Andreou Dimitris, email: jim.andreou (at) gmail (dot) com
 * @see <a href="http://en.wikipedia.org/wiki/Disjoint-set_data_structure">
 * Disjoint-set data structure article on Wikipedia</a>
 */
class Partition<E extends Comparable<? super E>> implements Comparable<Partition<E>> {
    private Partition<E> parent;
    private int rank;
    private final E value;

    private Partition(E value) {
        this.value = value;
        this.parent = this;
    }

    /**
     * Creates a partition of a singleton set, containing only itself. The created
     * partition is permanently associated with the specified value, which can
     * be accessed by {@linkplain #value()}.
     *
     * @param <E> the type of the user-defined value
     * @param value the value to associate with the created partition
     * @return the created partition
     */
    public static <E extends Comparable<? super E>> Partition<E> singleton(E value) {
        return new Partition<E>(value);
    }

    /**
     * Checks whether the two elements have been merged.
     *
     * <p>Equivalent to {@code partition1.find() == partition2.find()}.
     * @param partition1 the first element
     * @param partition2 the second element
     * @return whether the two partitions have been merged
     */
    public static boolean areMerged(Partition<?> partition1, Partition<?> partition2) {
        return partition1.find() == partition2.find();
    }

    /**
     * Returns the value associated with this partition upon creation.
     *
     * @return the value associated with this partition upon creation
     */
    public E getValue() {
        return value;
    }

    /**
     * Merges this partition with another one. This has the following implications:
     * <ul>
     * <li>{@code this.find() == other.find()} will be true, forever
     * <li>{@code Partition.areMerged(this, other)} will return true, forever
     * </ul>
     * @param other the partition to merge this partition with
     * @return a partition representing the merged partitions. It will be either equal to either
     *      {@code this.find()} or {@code other.find()}, i.e. one representative of the partitions
     *      which will be elected to represent the union
     */
    public Partition<E> merge(Partition<E> other) {
        Partition<E> root1 = other.find();
        Partition<E> root2 = find();
        if (root1.rank < root2.rank) {
            root1.parent = root2;
            return root2;
        } else if (root1.rank > root2.rank) {
            root2.parent = root1;
            return root1;
        } else {
            root2.parent = root1;
            root1.rank++;
            return root1;
        }
    }

    /**
     * Returns the unique representative of the set that this element belongs to. The
     * returned instance can be compared with the representative of another element,
     * to check whether the two elements belong to the same set (when the two
     * representatives will be identical)
     *
     * @return the unique representative of the set that this partition belongs to
     */
    public Partition<E> find() {
        //A single-pass path compressing algorithm
        Partition<E> current = this;
        Partition<E> last = this;
        while (current.parent != current) {
            last.parent = current.parent; //initially a no-op
            last = current;
            current = current.parent;
        }
        return current;
    }

    @Override
    public int compareTo(Partition<E> partition) {
        return this.value.compareTo(partition.value);
    }

    @Override
    public boolean equals(Object other) {
        if (other == null) return false;
        if (getClass() != other.getClass()) return false;

        Partition<?> that = (Partition<?>) other;

        return value == that.getValue();
    }

    @Override
    public int hashCode() {
        return 41 + value.hashCode();
    }
}
