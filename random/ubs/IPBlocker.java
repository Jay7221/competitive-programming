import java.util.*;
import java.util.regex.*;

public class IPBlocker {

    public static List<Integer> processRequests(String[] requests, String[] blacklisted_ips) {
        List<Integer> result = new ArrayList<>();

        // Storing the regex patterns for blacklisted IPs
        List<Pattern> patterns = new ArrayList<>();
        for (String regex : blacklisted_ips) {
            patterns.add(Pattern.compile(regex.replace("*", ".*")));
        }

        // Storing the requests with their indices
        Map<String, Queue<Integer>> requestIndices = new HashMap<>();

        // Processing each request
        for (int i = 0; i < requests.length; i++) {
            String request = requests[i];

            // Checking if the request matches any blacklisted IP
            boolean isBlocked = false;
            for (Pattern pattern : patterns) {
                if (pattern.matcher(request).matches()) {
                    isBlocked = true;
                    break;
                }
            }

            // Checking if the IP has sent at least 2 requests in the last 5 seconds
            Queue<Integer> indices = requestIndices.getOrDefault(request, new LinkedList<>());
            indices.add(i);

            while (!indices.isEmpty() && indices.peek() <= i - 5) {
                indices.poll();
            }

            if (indices.size() >= 2) {
                isBlocked = true;
            }

            requestIndices.put(request, indices);

            // Adding the result to the list
            result.add(isBlocked ? 1 : 0);
        }

        return result;
    }

    public static void main(String[] args) {
        // Example usage
        String[] blacklisted_ips = {"*.123.*", "1.2.*.4"};
        String[] requests = {"12.1.123.45", "1.123.435.12", "1.2.3.4", "1.2.3.4", "1.2.3.4"};

        List<Integer> blockedStatus = processRequests(requests, blacklisted_ips);

        // Printing the result
        for (int status : blockedStatus) {
            System.out.print(status + " ");
        }
    }
}

